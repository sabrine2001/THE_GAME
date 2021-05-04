#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "menu.h"
int main() 
{  
	enigme e;
     e=genererEnigme("aleatoire.txt");
	menu m;
	initialisation(&m);
while (m.continuer)
   {
     if(m.menu==0){menu0 (&m);}
else if(m.menu==1){enigme_g(&m,&e);}
else if(m.menu==2){menu2 (&m);}
afficher (&m); 
}
liberation(&m);
    return 0;
}
