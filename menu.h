#ifndef __menu_h__
#define __menu_h__
#include "enigme/aleatoire.h"
typedef struct
{
int wait,t,menu,x,y,loop,ps,ps2,fullscreen;
Uint32 flag;
    SDL_Surface *ecran,*temp,*anim[143],*menu2[15],*text,*image[13];
    SDL_Rect postemp,positionim[7],position[7];
    SDL_Color color;
    Mix_Music *musique;//pointeur musique jeux
	Mix_Chunk *MB,*MB2;//pointeur music boutton(chunk se defere de formart) chunk pour format wav ; Music pour format mp3
    SDL_Event event;//clavier et souris
    char convxy[30],load[25],load2[25];
 int continuer;//si continuer=1 il reste dans la boucle while ; si 0 il quite la boucle
    TTF_Font* font;
} menu;

void initialisation(menu *m);

void menu0(menu *m);

void menu1(menu *m);

void menu2(menu *m);

void liberation(menu *m);

void afficher (menu *m);
void enigme_g(menu *m,enigme *e);
#endif
