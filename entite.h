/**
* @file entite.h
* @brief tache entite.
* @author Ranim
* @version 0.1
* @date Apr 23, 2021
*/


#ifndef ENTITE_H_DEFINED
#define ENTITE_H_DEFINED

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>



/**
* @struct Cowboy
* @brief struct for Cowboy
*/
typedef struct
{
  SDL_Rect pos;
  int vx;
  int direction; // 0:left  1:right

  int detected_player;
  int is_moving;
  int is_colliding;

  int detection_range;
  SDL_Rect roam_range;

  // timers
  int start_chasing_timer;
  int start_roaming_timer;
  int start_pause_timer;
  int chase_duration;
  int roam_duration;
  int pause_roam_duration;

  SDL_Surface *display_frame;
  SDL_Surface *cowboy_stand;
  SDL_Surface *cowboy_run_left[15];
  SDL_Surface *cowboy_run_right[15];

} Cowboy;

/**
* @struct test
* @brief struct for test 
*/
typedef struct
{
  SDL_Surface *town_background;
  SDL_Surface *player_img;
  SDL_Rect player_pos;

} test;

int get_distance(SDL_Rect player, SDL_Rect enemie);
int get_random_num(int min, int max);

void init_enemie(Cowboy enemies[], int *enemies_spawned);
void afficher_enemie(Cowboy enemies[], int enemies_num, test others, SDL_Surface *surface);
void animer_enemie(Cowboy enemies[], int enemies_num);
void deplacer(Cowboy *enemie);
int collisionBB(test player, Cowboy enemie);
void deplacerIA(Cowboy *enemie, test others);
#endif
