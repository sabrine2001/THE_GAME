/** 
* @file aleatoire.c 
* @brief Testing Program. 
* @author C paradoxteam 
* @version 0.1 
* @date Apr 24, 2021 
* 
* Testing program for enigme aleatoire (avec fichier )* 
*/
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <stdbool.h>
#include <math.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "aleatoire.h"

enigme genererEnigme(char *nomfichier)
{   int n;
    n=nb_line(nomfichier);
    FILE* f;
    enigme e;
    srand( time( NULL ) );
    int alea = rand() % n,p=0;
    init_Back(&e);
    f=fopen(nomfichier,"r");
    while (p<alea)
    {
        fseek(f, 1, SEEK_CUR);
        if (fgetc(f)=='\n')
        {
            p++;
        }
        
    }    
    fscanf(f,"%s %s %s %s %s\n",e.question,e.rep1,e.rep2,e.rep3,e.solution);
    fclose(f);
    return e;
    
}
/** 
* @brief To generer enigme . 
* @param nomfichier the name of the file  
* @param url the url of the image  
* @return Nothing 
*/ 

void afficherEnigme(enigme *e, SDL_Surface * screen)
{
    SDL_Surface  *quest = NULL ,*rep1 = NULL ,*rep2 = NULL , *rep3 = NULL;
    SDL_Rect posQ,pos1,pos2,pos3;
    TTF_Font *police = NULL;
    SDL_Color couleurNoire = {0, 0, 0};    
    TTF_Init();
    police = TTF_OpenFont("horror.ttf", 32);
    quest = TTF_RenderText_Blended(police, e->question, couleurNoire);
    rep1 = TTF_RenderText_Blended(police, e->rep1, couleurNoire);
    rep2 = TTF_RenderText_Blended(police, e->rep2, couleurNoire);
    rep3 = TTF_RenderText_Blended(police, e->rep3, couleurNoire);
    posQ.x=150;
    posQ.y=100;
    pos1.x=50;
    pos1.y=300;
    pos2.x=300;
    pos2.y=300;
    pos3.x=550;
    pos3.y=300;
    afficher_Back(e->b[0],screen); 
    SDL_BlitSurface(quest, NULL, screen, &posQ); /* Blit du texte */
    SDL_BlitSurface(rep1, NULL, screen, &pos1); /* Blit du texte */
    SDL_BlitSurface(rep2, NULL, screen, &pos2); /* Blit du texte */
    SDL_BlitSurface(rep3, NULL, screen, &pos3); /* Blit du texte */





}
/** 
* @brief To display the enigme . 
* @param e , screen the enigme and teh screen 
* @param url the url of the image  
* @return Nothing 
*/ 

void init_Back(enigme *e)
{
	e->b[0].backgroundImg=IMG_Load("background.jpg");
	e->b[1].backgroundImg=IMG_Load("true.png");
	e->b[2].backgroundImg=IMG_Load("false.png");
	if (e->b[0].backgroundImg == NULL) 
	{
	printf ("unable to load : %s\n", SDL_GetError ());
	
	}
	e->b[0].backgroundPos.x=0;
	e->b[0].backgroundPos.y=0;
	e->b[0].backgroundPos.w=SCREEN_W;
	e->b[0].backgroundPos.h=SCREEN_H;
	e->b[1].backgroundPos.x=0;
	e->b[1].backgroundPos.y=0;
	e->b[1].backgroundPos.w=SCREEN_W;
	e->b[1].backgroundPos.h=SCREEN_H;
	e->b[2].backgroundPos.x=0;
	e->b[2].backgroundPos.y=0;
	e->b[2].backgroundPos.w=SCREEN_W;
	e->b[2].backgroundPos.h=SCREEN_H;
      
	
}
/** 
* @brief To initialize the background e.b . 
* @param e the enigme 
* @param url the url of the image  
* @return Nothing 
*/ 

void afficher_Back(background b, SDL_Surface * screen)
{
	SDL_BlitSurface(b.backgroundImg, &(b.backgroundPos), screen,NULL);
	 
}
/** 
* @brief To display the background b . 
* @param b,screen the background and the screen  
* @param url the url of the image  
* @return Nothing 
*/ 


void liberer_memoire(background b)
{ 
	SDL_FreeSurface(b.backgroundImg);	 
}
/** 
* @brief free memory . 
* @param b the background  
* @param url the url of the image  
* @return Nothing 
*/
int nb_line(char *nomfichier)
{
int c;
int n = 0;
FILE *f;
f=fopen(nomfichier,"r");
while ((c = getc(f)) != EOF){
    if (c == '\n')
        ++n;
}
 fclose(f);
return n;}
/** 
* @brief To calculate the numbre of lines in the file . 
* @param nomfile the file
* @param url the url of the image  
* @return Nothing 
*/ 

void resolution (enigme* e, char * rep ,SDL_Surface *screen,int * continuer)
{ 
    init_Back(e);
   
if(strcmp(e->solution,rep)==0)
{
printf("Vrai");
SDL_BlitSurface(e->b[1].backgroundImg, NULL, screen,&(e->b[1].backgroundPos));
SDL_Flip(screen);
SDL_Delay(40);
*continuer=0;
}
else 
{
printf("Faux");
SDL_BlitSurface(e->b[2].backgroundImg,NULL, screen,&(e->b[2].backgroundPos));
SDL_Flip(screen);
SDL_Delay(40);
*continuer=0;
}

}
/** 
* @brief To initialize the background b . 
* @param b the background 
* @param url the url of the image  
* @return Nothing 
*/
