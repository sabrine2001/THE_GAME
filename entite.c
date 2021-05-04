/**
* @file entite.c
* @brief tache entite.
* @author Ranim
* @version 0.1
* @date Apr 23, 2021
*/


#include "./entite.h"
/**
* @brief To initialize the enemie 
* @param  enemies the cowboy 
* @param  enemies-spawned
* @return Nothing
*/

void init_enemie(Cowboy enemies[], int *enemies_spawned)
{
  Cowboy new_en;

  // setting initial coords
  int max_tries = 0;
  int too_close = 0;
  do
  {
    new_en.pos.x = get_random_num(100, 600);
    for (int i = 0; i < *enemies_spawned; i++)
    {
      if (get_distance(new_en.pos, enemies[i].pos) < 100)
        too_close = 1;
      else
        too_close = 0;
    }

    max_tries++;
  } while (max_tries < 10000 && too_close == 1);
  new_en.pos.y = 300;
  new_en.pos.w = 100;
  new_en.pos.h = 209;

  new_en.vx = 2;

  new_en.detected_player = 0;
  new_en.direction = 0;

  new_en.detection_range = 300;
  new_en.roam_range.x = new_en.pos.x;
  new_en.roam_range.y = new_en.pos.y;
  new_en.roam_range.w = 100;

  new_en.start_chasing_timer = 0;
  new_en.start_roaming_timer = 0;
  new_en.start_pause_timer = 0;
  new_en.chase_duration = 0;
  new_en.roam_duration = 0;
  new_en.pause_roam_duration = 0;

  // standing
  new_en.cowboy_stand = IMG_Load("./assets/right/0.png");

  // moving right
  new_en.cowboy_run_right[0] = IMG_Load("./assets/right/0.png");
  new_en.cowboy_run_right[1] = IMG_Load("./assets/right/1.png");
  new_en.cowboy_run_right[2] = IMG_Load("./assets/right/2.png");
  new_en.cowboy_run_right[3] = IMG_Load("./assets/right/3.png");
  new_en.cowboy_run_right[4] = IMG_Load("./assets/right/4.png");
  new_en.cowboy_run_right[5] = IMG_Load("./assets/right/5.png");
  new_en.cowboy_run_right[6] = IMG_Load("./assets/right/6.png");
  new_en.cowboy_run_right[7] = IMG_Load("./assets/right/7.png");
  new_en.cowboy_run_right[8] = IMG_Load("./assets/right/8.png");
  new_en.cowboy_run_right[9] = IMG_Load("./assets/right/9.png");
  new_en.cowboy_run_right[10] = IMG_Load("./assets/right/10.png");
  new_en.cowboy_run_right[11] = IMG_Load("./assets/right/11.png");
  new_en.cowboy_run_right[12] = IMG_Load("./assets/right/12.png");
  new_en.cowboy_run_right[13] = IMG_Load("./assets/right/13.png");
  new_en.cowboy_run_right[14] = IMG_Load("./assets/right/14.png");

  // moving left
  new_en.cowboy_run_left[0] = IMG_Load("./assets/left/0.png");
  new_en.cowboy_run_left[1] = IMG_Load("./assets/left/1.png");
  new_en.cowboy_run_left[2] = IMG_Load("./assets/left/2.png");
  new_en.cowboy_run_left[3] = IMG_Load("./assets/left/3.png");
  new_en.cowboy_run_left[4] = IMG_Load("./assets/left/4.png");
  new_en.cowboy_run_left[5] = IMG_Load("./assets/left/5.png");
  new_en.cowboy_run_left[6] = IMG_Load("./assets/left/6.png");
  new_en.cowboy_run_left[7] = IMG_Load("./assets/left/7.png");
  new_en.cowboy_run_left[8] = IMG_Load("./assets/left/8.png");
  new_en.cowboy_run_left[9] = IMG_Load("./assets/left/9.png");
  new_en.cowboy_run_left[10] = IMG_Load("./assets/left/10.png");
  new_en.cowboy_run_left[11] = IMG_Load("./assets/left/11.png");
  new_en.cowboy_run_left[12] = IMG_Load("./assets/left/12.png");
  new_en.cowboy_run_left[13] = IMG_Load("./assets/left/13.png");
  new_en.cowboy_run_left[14] = IMG_Load("./assets/left/14.png");

  // adding the new cowboy to the array
  enemies[*enemies_spawned] = new_en;
  (*enemies_spawned)++;
}
/**
* @brief To get_random_num
* @param min the minimum
* @param max the maximum 
* @return int
*/

int get_random_num(int min, int max)
{
  int rand_num = 0;
  rand_num = (rand() % (max + 1 - min)) + min;

  return rand_num;
}
/**
* @brief To get_distance
* @param player the thief 
* @param enemie the cowboy
* @return int
*/
int get_distance(SDL_Rect player, SDL_Rect enemie)
{
  return sqrt(pow(player.x - enemie.x, 2) + pow(player.y - enemie.y, 2));
}
/**
* @brief To move the enemie 
* @param enemie the cowboy  
* @return Nothing
*/
void deplacer(Cowboy *enemie)
{
  if (enemie->is_moving)
  {
    if (enemie->direction == 0)
      enemie->pos.x -= enemie->vx;
    else
      enemie->pos.x += enemie->vx;
  }
}
/**
* @brief To moveIA the enemie 
* @param enemie the cowboy 
* @param others 
* @return Nothing
*/
void deplacerIA(Cowboy *enemie, test others)
{
  // detect player
  if (get_distance(others.player_pos, enemie->pos) < enemie->detection_range || enemie->detected_player == 1)
  {
    if (enemie->start_chasing_timer == 0)
    {
      enemie->start_chasing_timer = SDL_GetTicks();
      enemie->detected_player = 1;
    }
    else if (SDL_GetTicks() - enemie->start_chasing_timer > 4000)
    {
      enemie->start_chasing_timer = 0;
      enemie->detected_player = 0;
    }
    else if (others.player_pos.y > enemie->pos.y + 100)
    {
      enemie->start_chasing_timer = 0;
      enemie->detected_player = 0;
    }
  }

  // roam mode
  if (enemie->detected_player == 0)
  {
    if (enemie->start_roaming_timer != 0)
    {
      enemie->is_moving = 1;

      if (SDL_GetTicks() - enemie->start_roaming_timer > enemie->roam_duration)
      {
        enemie->start_roaming_timer = 0;
        enemie->roam_duration = 0;
      }
      else
      {
        if (get_distance(enemie->pos, enemie->roam_range) > enemie->roam_range.w)
        {
          if (enemie->pos.x > enemie->roam_range.x)
          {
            enemie->direction = 0;
          }
          else
          {
            enemie->direction = 1;
          }
        }
      }
    }
    else
    {
      enemie->is_moving = 0;
      if (enemie->start_pause_timer == 0)
      {

        enemie->start_pause_timer = SDL_GetTicks();
        enemie->pause_roam_duration = get_random_num(3000, 4000);
      }
      else if (SDL_GetTicks() - enemie->start_pause_timer > enemie->pause_roam_duration)
      {
        enemie->start_roaming_timer = SDL_GetTicks();
        enemie->roam_duration = get_random_num(1000, 2000);
        enemie->direction = get_random_num(0, 1);

        enemie->start_pause_timer = 0;
        enemie->pause_roam_duration = 0;
      }
    }
  }
  // chase mode
  else if (enemie->detected_player == 1)
  {
    enemie->is_moving = 1;

    if (others.player_pos.x > enemie->pos.x)
      enemie->direction = 1;
    else
      enemie->direction = 0;
  }
}
/**
* @brief To show the enemie
* @param  enemies the cowboy
* @param enemies_num 
* @param  others 
* @param surface the surface 
* @return Nothing
*/
void afficher_enemie(Cowboy enemies[], int enemies_num, test others, SDL_Surface *surface)
{

  SDL_BlitSurface(others.town_background, NULL, surface, NULL);
  SDL_BlitSurface(others.player_img, NULL, surface, &(others.player_pos));

  for (int i = 0; i < enemies_num; i++)
  {
    SDL_BlitSurface(enemies[i].display_frame, NULL, surface, &enemies[i].pos);
  }
}

/**
* @brief To animate the enemie 
* @param  enemies the cowboy 
* @param enemies_num 
* @return Nothing
*/
void animer_enemie(Cowboy enemies[], int enemies_num)
{
  static int timer = 0;
  static int animation = 0;

  for (int i = 0; i < enemies_num; i++)
  {
    if (enemies[i].is_moving == 0)
    {
      enemies[i].display_frame = enemies[i].cowboy_stand;
      animation = 0;
    }
    else
    {
      if (SDL_GetTicks() - timer > 70)
      {
        timer = SDL_GetTicks();
        animation = (animation + 1) % 15;
      }

      if (enemies[i].direction == 0)
      {
        enemies[i].display_frame = enemies[i].cowboy_run_left[animation];
      }
      else
      {
        enemies[i].display_frame = enemies[i].cowboy_run_right[animation];
      }
    }
  }
}

/**
* @brief To collision  
* @param player the thief 
* @param enemie the cowboy 
* @return int
*/

int collisionBB(test player, Cowboy enemie)
{
  int collision = 0;
  if (enemie.pos.x < player.player_pos.x + player.player_pos.w && enemie.pos.x > player.player_pos.x)
  {
    if (player.player_pos.y > enemie.pos.y && player.player_pos.y < enemie.pos.y + enemie.pos.h)
    {
      collision = 1;
    }
  }
  return collision;
}
