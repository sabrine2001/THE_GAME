#ifndef MULTIJOUEUR_H_INCLUDED
#define MULTIJOUEUR_H_INCLUDED
/**
*@struct clocke
*@brief struct for clocke
*/
typedef struct{
SDL_Rect pos;
SDL_Surface *solid;
char texttemp[10];
SDL_Color color;
TTF_Font *police;
time_t timer,pred;
int save;
}clocke;
/**
*@struct personne
*@brief struct for personne
*/
typedef struct{
SDL_Rect pos;
}Personne;
/**
*@struct minimap
*@brief struct for minimap
*/
typedef struct{
SDL_Surface *joueur,*map;
SDL_Rect posjoueur;
}minimap;
void initmap( minimap * m);
void initclock( clocke * c);
void  afficherminimap (minimap m, SDL_Surface * window,SDL_Rect pos);
void affichertemps (clocke *c,SDL_Surface *window);
SDL_Color GetPixel(SDL_Surface *pSurface,int x,int y);
int collisionPP( Personne p, SDL_Surface * Masque);

#endif // MULTIJOUEUR_H_INCLUDED
