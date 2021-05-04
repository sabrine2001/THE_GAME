/**
* @file background.c
* @brief tache background.
* @author Sabrine
* @version 0.1
* @date Apr 23, 2021
*/

#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "background.h"
#define SCREEN_W 900
#define SCREEN_H 900


/**
* @brief To initialize the background b
* @param b the background
* @return Nothing
*/
void init_Back(background * b)
{

	b->backgroundImg = IMG_Load ("b.png");
	if (b->backgroundImg == NULL)
	{
	printf ("unable to load bitmap: %s\n", SDL_GetError ());

	}
	b->backgroundPos.x=0;
	b->backgroundPos.y=0 ;
	b->backgroundPos.w=SCREEN_W/2;  
	b->backgroundPos.h=SCREEN_H;

}


/**
* @brief To show the background b
* @param b the background
* @param screen the screen
* @return Nothing
*/
void afficher_Back(background b, SDL_Surface * screen)
{
	SDL_BlitSurface(b.backgroundImg, &(b.backgroundPos), screen,NULL);
}


/**
* @brief To initialize the second background b
* @param b the background
* @return Nothing
*/
void init_Back_pe(background * b)
{
    //partage d'ecran

	b->posEcran2.x=SCREEN_W/2 + 2;
	b->posEcran2.y=0;
	b->posEcran2.w=SCREEN_W/2;
	b->posEcran2.h=SCREEN_H;
}


/**
* @brief To show the second background b
* @param b the background
* @param screen the screen
* @return Nothing
*/
void afficher_Back_pe(background b, SDL_Surface * screen)
{
    //partage d'ecran

    SDL_BlitSurface(b.backgroundImg, NULL,screen,&(b.posEcran2));
}

/*
void partage_d_ecran(background * b, SDL_Surface * screen)
{
    int keysHeld[323]={0};

    init_Back_pe(b);
    afficher_Back_pe(*b,*screen);

    SDLPollEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
            continuer=1;break;
            case SDL_KEYDOWN
            keysHeld[event.key.keysym.sym]=1;break;
            case SDL_KEYUP
            keysHeld[event.key.keysym.sym]=0;break;

        }





}  */


/**
* @brief To scroll the background
* @param b the background
* @param direction the direction of scrolling
* @param numBACK the number of background to scroll
* @return Nothing
*/
void scrolling (background * b,int direction,int numBACK)
{
    switch(numBACK)
    {
        case 1:
        {
            switch(direction)
            {
                case -1 :
                b->backgroundPos.x--;break;
                case 1 :
                b->backgroundPos.x++;break;
                case -2 :
                b->backgroundPos.y--;break;
                case 2 :
                b->backgroundPos.y++;break;
            }
                    if(b->backgroundPos.x > b->backgroundImg->w-SCREEN_W)
                    b->backgroundPos.x=0;
                    if(b->backgroundPos.x<0)
                    b->backgroundPos.x=0;
        }
        case 2:
        {
            switch(direction)
            {
                case -1 :
                b->posEcran2.x--;break;
                case 1 :
                b->posEcran2.x++;break;
                case -2 :
                b->posEcran2.y--;break;
                case 2 :
                b->posEcran2.y++;break;
            }
                    if(b->posEcran2.x > b->backgroundImg->w-SCREEN_W)
                    b->posEcran2.x=0;
                    if(b->posEcran2.x<0)
                    b->posEcran2.x=0;
        }
    }

}
