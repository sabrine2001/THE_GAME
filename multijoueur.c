/**
*@file multijoueur.c
*@brif tache multijoueur
*@author safa
*@version 0.1
*@date apr 23,2021
*/

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <time.h>
#include "multijoueur.h"
/**
*@brif to initialize minimap m
*@param m the minimap 
*@return nothing
*/
void initmap( minimap * m){
m->map=IMG_Load("image/BCKG.png");
m->joueur=IMG_Load("image/minijoueur.png");

m->posjoueur.x=350;
m->posjoueur.y=44;
}
/**
*@brif to initialize clocke c
*@param c the clocke 
*@return nothing
*/
void initclock( clocke * c){
c->pos.x=50;
c->pos.y=50;
c->color.r=172;
c->color.g=108;
c->color.b=73;
c->police=TTF_OpenFont("image/BlackWolf.ttf",40);
c->timer=time(NULL);
c->pred=time(NULL);
c->save=0;
}
/**
*@brif to show the minimap m
*@param m the minimap 
*@return nothing
*/
void  afficherminimap (minimap m, SDL_Surface * window,SDL_Rect pos){
SDL_BlitSurface(m.map,NULL,window,NULL);
m.posjoueur.x=(int)350+(pos.x/10);
SDL_BlitSurface(m.joueur,NULL,window,&m.posjoueur);
}
/********************************************/
/**
*@brif to show temps
*@param c clocke 
*@return nothing
*/
void affichertemps (clocke *c,SDL_Surface *window){
int m,s;
 char min[3],sec[3];
c->timer=time(NULL);
if(c->timer!=c->pred){
c->pred=c->timer;
c->save++;
}
m=(int)(c->save)/60;
s=c->save%60;
sprintf(min,"%d",m);
sprintf(sec,"%d",s);
if(m==0){min[0]='0';min[1]='0';}
else if(m<10){
min[1]=min[0];
min[0]='0';
}
if(s==0){sec[0]='0';sec[1]='0';}
else if(s<10){
sec[1]=sec[0];
sec[0]='0';
}
strcpy(c->texttemp,min);
strcat(c->texttemp,":");
strcat(c->texttemp,sec);
c->solid=TTF_RenderText_Blended(c->police,c->texttemp,c->color);
SDL_BlitSurface(c->solid,NULL,window,&c->pos);
}
SDL_Color GetPixel(SDL_Surface *pSurface,int x,int y){
SDL_Color color;
Uint32 col=0;
//detection position
char*pPosition=(char*)pSurface->pixels;
pPosition+=(pSurface->pitch*y);
pPosition+=(pSurface->format->BytesPerPixel*x);
memcpy(&col,pPosition,pSurface->format->BytesPerPixel);
//convertircolor
SDL_GetRGB(col,pSurface->format,&color.r,&color.g,&color.b);
return(color);
}
/**
*@brif to initialize collisionPP
*@param p personne 
*@return nothing
*/
int collisionPP( Personne p, SDL_Surface * Masque){
SDL_Color color[8];
color[0]=GetPixel(Masque,p.pos.x,p.pos.y);
color[1]=GetPixel(Masque,p.pos.x+p.pos.w/2,p.pos.y);
color[2]=GetPixel(Masque,p.pos.x+p.pos.w,p.pos.y);
color[3]=GetPixel(Masque,p.pos.x,p.pos.y+p.pos.h/2);
color[4]=GetPixel(Masque,p.pos.x,p.pos.y+p.pos.h);
color[5]=GetPixel(Masque,p.pos.x+p.pos.w/2,p.pos.y+p.pos.h);
color[6]=GetPixel(Masque,p.pos.x+p.pos.w,p.pos.y+p.pos.h);
color[7]=GetPixel(Masque,p.pos.x+p.pos.w,p.pos.y+p.pos.h/2);
int i=0;
while(i<8&& color[i].r!=0)
i++;
return i!=8;
}



