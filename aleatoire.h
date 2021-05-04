#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <stdbool.h>
#include <time.h>
#define  SCREEN_W 1000
#define  SCREEN_H 600

typedef struct background{
	SDL_Surface *backgroundImg;
	SDL_Rect backgroundPos;
} background;
/** 
* @struct Background 
* @brief struct for backround 
*/ 


typedef struct enigme
{
    background b[3];
    char question[50],rep1[15],rep2[15],rep3[15];
    char solution[20];
}enigme;  
/** 
* @struct Enigme
* @brief struct for enigme 
*/ 

void init_Back2(background b[3]);
void init_Back(enigme *e);

void afficher_Back(background b, SDL_Surface * screen);
enigme genererEnigme(char *nomfichier);
void afficherEnigme(enigme *e, SDL_Surface * screen);
void liberer_memoire(background b);
int nb_line(char *nomfichier);
void resolution (enigme* e, char *rep ,SDL_Surface *screen,int *continuer);
