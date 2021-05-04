/**
* @file background.h
* @brief tache background.
* @author Sabrine
* @version 0.1
* @date Apr 23, 2021
*/

#ifndef BACKGROUND_H
#define BACKGROUND_H
#define SCREEN_W 900
#define SCREEN_H 900
#include <SDL/SDL.h>


/**
* @struct Background
* @brief struct for backround
*/
struct background{
	SDL_Surface *backgroundImg;   /*!< Surface. */
	SDL_Rect backgroundPos;       /*!< Rectangle*/
	SDL_Rect camera[2];           /*!< Rectangle*/
	SDL_Rect posEcran2;           /*!< Rectangle*/
};
typedef struct background background;


void init_Back(background * b);
void afficher_Back(background b, SDL_Surface * screen);

void init_Back_pe(background * b);
void afficher_Back_pe(background b, SDL_Surface * screen);


void scrolling (background * b,int direction,int numBACK);
#endif
