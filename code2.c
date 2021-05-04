#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "menu.h"

void initialisation(menu *m){
int i;
m->menu=0;
	m->loop=0;
	m->ps=0;
	m->ps2=0;
	m->wait=-1; 
m->flag=SDL_HWSURFACE;
	m->t=5;
	m->fullscreen=0;
      TTF_Init();
    SDL_Init(SDL_INIT_EVERYTHING); // Initialisation de la SDL
    m->ecran=SDL_SetVideoMode(800, 564, 32, m->flag); // Ouverture de la fenêtre
 for(i=0;i<143;i++){sprintf(m->load,"animbg/%d.png",i);
 m->anim[i]=IMG_Load(m->load);}
    m->font=TTF_OpenFont("HORROR VISION DEMO.ttf",30);
    m->positionim[1].x = 434;
    m->positionim[1].y = 318 ;
    m->positionim[2].x =434 ;
    m->positionim[2].y = 376;
    m->positionim[3].x =434;
    m->positionim[3].y = 434 ;
    m->positionim[4].x =434;
    m->positionim[4].y = 492;
    m->position[1].x = 300;
    m->position[1].y = 196 ;
    m->position[2].x = 520;
    m->position[2].y = 196;
    m->position[3].x =236;
    m->position[3].y = 196;
    m->position[4].x =248;
    m->position[4].y = 290;
    m->position[5].x = 474;
    m->position[5].y = 290 ;
    m->position[6].x =327 ;
    m->position[6].y = 375;
    m->image[1]= IMG_Load("menu/1.png");
    m->image[2]= IMG_Load("menu/3.png");
    m->image[3]= IMG_Load("menu/5.png");
    m->image[4]= IMG_Load("menu/7.png");
    m->image[5]= IMG_Load("menu/2.png");
    m->image[6]= IMG_Load("menu/4.png");
    m->image[7]= IMG_Load("menu/6.png");
    m->image[8]= IMG_Load("menu/8.png");
    m->image[9]= IMG_Load("menu/20.png");
    m->image[10]= IMG_Load("menu/40.png"); 
    m->image[11]= IMG_Load("menu/60.png"); 
    m->image[12]= IMG_Load("menu/80.png");
    for(i=0;i<15;i++){sprintf(m->load2,"1/%d.png",i);
   m->menu2[i]=IMG_Load(m->load2);}
    
	m->color.r=250;
	m->color.g=250;
	m->color.b=250;

    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)// initiliser mixer
    {
        printf("%s",Mix_GetError());
    }

    
    m->musique = Mix_LoadMUS("hit.mp3");//m->musique jeux
    Mix_PlayMusic(m->musique, -1);//repeter la music de jeux (boucle infinie)
    m->MB = Mix_LoadWAV("selectmony.wav");// clique de bouton
 m->MB2 = Mix_LoadWAV("click.wav");
}
void menu0(menu *m){
    
SDL_BlitSurface(m->anim[m->loop], NULL, m->ecran, NULL);//affichage de menu
m->loop++;if(m->loop==143){m->loop=0;}
    SDL_BlitSurface(m->image[1],NULL,m->ecran,&m->positionim[1]);
    SDL_BlitSurface(m->image[2],NULL,m->ecran,&m->positionim[2]);
        SDL_BlitSurface(m->image[3],NULL,m->ecran,&m->positionim[3]);
	SDL_BlitSurface(m->image[4],NULL,m->ecran,&m->positionim[4]);
	
while(SDL_PollEvent(&m->event)){
       switch(m->event.type)
        {
        case SDL_QUIT:
            m->continuer = 0;
            break;
        case SDL_KEYDOWN :
        switch(m->event.key.keysym.sym){
			 case SDLK_ESCAPE:
			m->continuer = 0;
			break;
			}
           break;
        case SDL_MOUSEBUTTONDOWN :
    if(m->event.button.button==SDL_BUTTON_LEFT){
							m->x=m->event.button.x;
							m->y= m->event.button.y;
		if (m->x >446 && m->y >333 && m->x < 749 && m->y <383)//les cordonnee win bch tenzel b souris(cordonnee mtaa bouton plam->y)
		{Mix_PlayChannel(2, m->MB2, 0); }
              else if (m->x >453 && m->y >397 && m->x <750 && m->y <440)
                { Mix_PlayChannel(2, m->MB2, 0);}
               else if (m->x >455 &&m->y >450 &&m->x <752  && m->y <496)
		{ Mix_PlayChannel(2, m->MB2, 0);}
                else if (m->x >456&& m->y >505 && m->x < 756 && m->y <556)
                { Mix_PlayChannel(2, m->MB2, 0);}
          
    if (m->x >446 && m->y >333 && m->x < 749 && m->y <383)//les cordonnee win bch tenzel b souris(cordonnee mtaa bouton plam->y)
                {
                    SDL_BlitSurface(m->image[9],NULL, m->ecran, &m->positionim[1]);//new tech3el
 //tech3el w tetfa w tehseb bel ms ;ex: SDL_Delam->y(ms)
					m->wait=m->t;
					m->temp=m->image[9];
					m->postemp=m->positionim[1];
          }else if (m->x >453 && m->y >397 && m->x <750 && m->y <440)
                {
                    SDL_BlitSurface(m->image[10],NULL, m->ecran, &m->positionim[2]);//settings tech3el
                    m->wait=m->t;
					m->temp=m->image[10];
					m->postemp=m->positionim[2];}
               else if (m->x >455 &&m->y >450 &&m->x <752  && m->y <496)
{
                    SDL_BlitSurface(m->image[11],NULL, m->ecran, &m->positionim[3]);//credit tech3el
					m->wait=m->t;
					m->temp=m->image[11];
					m->postemp=m->positionim[3];}
                else if (m->x >456&& m->y >505 && m->x < 756 && m->y <556 )
            {SDL_BlitSurface(m->image[12],NULL, m->ecran, &m->positionim[4]);//quit tech3el
                    m->wait=m->t;
					m->temp=m->image[12];
					m->postemp=m->positionim[4]; }
			
              }
        
           break;
        case SDL_MOUSEMOTION :
                  {
					  m->x=m->event.motion.x;
					  m->y=m->event.motion.y;

            }break;
      }
      }
                      if (m->x >446 && m->y >333 && m->x < 749 && m->y <383&&(m->ps==0))//les cordonnee win bch tenzel b souris(cordonnee mtaa bouton play)
              {m->ps=1;
 //tech3el w tetfa w tehseb bel ms ;ex: SDL_Delay(ms)
                    Mix_PlayChannel(1, m->MB, 0); 
     }else if (m->x >453 && m->y >397 && m->x <750 && m->y <440 &&(m->ps==0))
                {m->ps=1;
              Mix_PlayChannel(1, m->MB, 0);
}
               else if (m->x >455 &&m->y >450 &&m->x <752  && m->y <496&&(m->ps==0))
{   m->ps=1;    
				Mix_PlayChannel(1, m->MB, 0);
                }
                else if (m->x >456&& m->y >505 && m->x < 756 && m->y <556&&(m->ps==0) )
                {m->ps=1;
                    Mix_PlayChannel(1, m->MB, 0);
                  }
    ////////////////////////////////////////////////////////////////////////
                               if (m->x >446 && m->y >333 && m->x < 749 && m->y <383)//les cordonnee win bch tenzel b souris(cordonnee mtaa bouton play)
                {
                    SDL_BlitSurface(m->image[5],NULL, m->ecran, &m->positionim[1]);//new tech3el
 //tech3el w tetfa w tehseb bel ms ;ex: SDL_Delay(ms) 
     }else if (m->x >453 && m->y >397 && m->x <750 && m->y <440)
                {
                    SDL_BlitSurface(m->image[6],NULL, m->ecran, &m->positionim[2]);//settings tech3el
   
}
               else if (m->x >455 &&m->y >450 &&m->x <752  && m->y <496)
{
                    SDL_BlitSurface(m->image[7],NULL, m->ecran, &m->positionim[3]);//credit tech3el

                }
                else if (m->x >456&& m->y >505 && m->x < 756 && m->y <556 )
                {
                    SDL_BlitSurface(m->image[8],NULL, m->ecran, &m->positionim[4]);//quit tech3el
                         }else{m->ps=0;}
         
if(m->wait>0){m->wait--;
 SDL_BlitSurface(m->temp,NULL, m->ecran, &m->postemp);
}if(m->wait==0){if(m->temp==m->image[12]){m->continuer=0;}}
if(m->wait==0){if(m->temp==m->image[9]){m->menu=1;m->wait=-1;}}
if(m->wait==0){if(m->temp==m->image[10]){m->menu=2;m->wait=-1;}}   
}

void menu1(menu *m){
SDL_Rect pos={100,300,0,0};
pos.w=m->menu2[11]->w;
pos.h=m->menu2[11]->h;
 SDL_BlitSurface(m->anim[m->loop], NULL, m->ecran, NULL);//affichage de menu
m->loop++;if(m->loop==143){m->loop=0;}
 SDL_BlitSurface(m->menu2[11],NULL,m->ecran,&pos);
pos.y+=100;
SDL_BlitSurface(m->menu2[13],NULL,m->ecran,&pos);
while(SDL_PollEvent(&m->event)){
       switch(m->event.type)
        {
        case SDL_QUIT:
            m->menu = 0;
            break;
        
        case SDL_KEYDOWN :
        switch(m->event.key.keysym.sym){
			
			case SDLK_h:
			m->menu = 0;
			
			break;
			case SDLK_ESCAPE:
			m->menu = 0;
			break;
			
			}
           break;
	case SDL_MOUSEMOTION:
	m->x=m->event.motion.x;
	m->y=m->event.motion.y;
	break;
		  
 }}
pos.y=300;
if(m->x>pos.x&&m->y>pos.y&&m->x<pos.x+pos.w&&m->y<pos.y+pos.h){SDL_BlitSurface(m->menu2[12],NULL,m->ecran,&pos);m->menu=2;}
pos.y=400;
if(m->x>pos.x&&m->y>pos.y&&m->x<pos.x+pos.w&&m->y<pos.y+pos.h){SDL_BlitSurface(m->menu2[14],NULL,m->ecran,&pos);}

}
void menu2(menu*m){


		  SDL_BlitSurface(m->menu2[0], NULL, m->ecran, NULL);//affichage de m->menu
       SDL_BlitSurface(m->menu2[6],NULL,m->ecran,&m->position[1]);
       SDL_BlitSurface(m->menu2[7],NULL,m->ecran,&m->position[2]);
       SDL_BlitSurface(m->menu2[9],NULL,m->ecran,&m->position[3]);
       SDL_BlitSurface(m->menu2[3],NULL,m->ecran,&m->position[4]);
       SDL_BlitSurface(m->menu2[1+m->fullscreen],NULL,m->ecran,&m->position[6]);
       SDL_BlitSurface(m->menu2[4],NULL,m->ecran,&m->position[5]);
       while(SDL_PollEvent(&m->event)){
       switch(m->event.type)
        {
	
        case SDL_QUIT:
            m->menu = 0;
            break;

        
        case SDL_KEYDOWN :
        switch(m->event.key.keysym.sym){
			case SDLK_h:
			m->menu = 0;
			break;
			case SDLK_f:
			
if(m->fullscreen==0){
m->flag=SDL_HWSURFACE |SDL_FULLSCREEN;
}else{
m->flag=SDL_HWSURFACE;	
              }	
m->fullscreen=!m->fullscreen;
m->ecran=SDL_SetVideoMode(800, 564, 32, m->flag);	
           
			break;
			case SDLK_ESCAPE:
			m->menu = 0;
			break;
			case SDLK_PLUS:
			
                    SDL_BlitSurface(m->menu2[8],NULL, m->ecran, &m->position[2]);
                   
					break;
			}
			case SDL_MOUSEBUTTONDOWN :
    if(m->event.button.button==SDL_BUTTON_LEFT){
				m->x=m->event.button.x;
				m->y= m->event.button.y;
		if (m->x >520 && m->y >196 && m->x < 570 && m->y <238)//les cordonnee win bch tenzel b souris(cordonnee mtaa bouton play)
		{Mix_PlayChannel(2, m->MB2, 0); }
              else if (m->x >236 && m->y >196 && m->x <284 && m->y <238)
                { Mix_PlayChannel(2, m->MB2, 0);}
               else if (m->x >474 &&m->y >290 &&m->x <542 && m->y <334)
		{ Mix_PlayChannel(2, m->MB2, 0);}
                else if (m->x >327 && m->y >375 && m->x < 481 && m->y <426)
                { Mix_PlayChannel(2, m->MB2, 0);}
          
    if (m->x >520 && m->y >196 && m->x < 570 && m->y <238)//les cordonnee win bch tenzel b souris(cordonnee mtaa bouton play)
                {
                    SDL_BlitSurface(m->menu2[8],NULL, m->ecran, &m->position[2]);//new tech3el
 //tech3el w tetfa w tehseb bel ms ;ex: SDL_Delam->y(ms)
		if(Mix_VolumeMusic(-1)<118){Mix_VolumeMusic(Mix_VolumeMusic(-1)+10);}else{Mix_VolumeMusic(128);}
          }else if (m->x >236 && m->y >196 && m->x <284 && m->y <238)
                {	
		if(Mix_VolumeMusic(-1)>10){Mix_VolumeMusic(Mix_VolumeMusic(-1)-10);}else{Mix_VolumeMusic(0);}
                    SDL_BlitSurface(m->menu2[10],NULL, m->ecran, &m->position[3]);}
               else if (m->x >474 &&m->y >290 &&m->x <542 && m->y <334)
{			Mix_VolumeMusic(0);
                    SDL_BlitSurface(m->menu2[5],NULL, m->ecran, &m->position[5]);

}
                else if (m->x >327 && m->y >375 && m->x < 481 && m->y <426 )
            {
if(m->fullscreen==0){
m->flag=SDL_HWSURFACE |SDL_FULLSCREEN;
}else{
m->flag=SDL_HWSURFACE;	
              }	
m->fullscreen=!m->fullscreen;
m->ecran=SDL_SetVideoMode(800, 600, 32, m->flag);}	
           }break;
		  
		  }}
		  
}
void enigme_g(menu *m,enigme *e)
{ static char rep[20];
 static int j,repondu=0;
afficherEnigme(e,m->ecran);
 SDL_Flip(m->ecran);
    while(SDL_PollEvent(&m->event))
	{

		switch(m->event.type)
		{
		case SDL_QUIT:

			m->continuer=0;
		break;
        case SDL_KEYDOWN:
			switch (m->event.key.keysym.sym)
			{
			
			case SDLK_a :
               
                repondu=1;
      		break;
            case SDLK_z :
                
                
                repondu=2;
            break;
            case SDLK_e:
              
              
                repondu=3;
            break;
            }
        break;
        }
        if (repondu==1) 
        {
         sprintf(rep,"%s",e->rep1);
         resolution ( e,rep ,m->ecran,&m->continuer);
        }
        if (repondu==2) 
        {
         sprintf(rep,"%s",e->rep2);
         resolution ( e,rep ,m->ecran,&m->continuer);
        }
        if (repondu==3) 
        {
         sprintf(rep,"%s",e->rep3);
         resolution ( e,rep ,m->ecran,&m->continuer);
        }
    }

}
void liberation(menu *m){
int i;
for(i=0;i<143;i++)
SDL_FreeSurface(m->anim[i]); 
for(i=0;i<15;i++)
SDL_FreeSurface(m->menu2[i]); 

 SDL_FreeSurface(m->text);  
SDL_FreeSurface(m->ecran);
SDL_FreeSurface(m->image[1]);
SDL_FreeSurface(m->image[2]);
SDL_FreeSurface(m->image[3]);
SDL_FreeSurface(m->image[4]);
SDL_FreeSurface(m->image[5]);
SDL_FreeSurface(m->image[6]);
SDL_FreeSurface(m->image[7]);
SDL_FreeSurface(m->image[8]);

 Mix_FreeMusic(m->musique);//free espace memoire
    Mix_CloseAudio();//tsakr e sout
    TTF_CloseFont(m->font);
    TTF_Quit();
    SDL_Quit(); // Arrêt de la SDL

}
void afficher (menu *m){
char convxy[30];
sprintf(convxy,"WELCOME x=%d y=%d",m->x,m->y);
m->text=TTF_RenderText_Solid(m->font,convxy,m->color);//convertire un message vers une m->image
 SDL_BlitSurface(m->text,NULL, m->ecran,NULL);
SDL_Flip(m->ecran);
SDL_Delay(40);
}
