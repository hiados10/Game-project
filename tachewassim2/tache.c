#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "tache.h"
void init_pers(player* p,int choix)
{p->position.x=0;
p->position.y=600;
p->stage=1;
p->vie=3;
p->enig1=0;
p->enig1=0;
}

void souris(SDL_Event event,SDL_Rect* positionimage,SDL_Surface *screen,SDL_Rect* positionscreen)
{ int x,y,s=0;
	SDL_Surface *image=NULL,*obstacle =NULL,*fond=NULL;
	SDL_GetMouseState(&x,&y);
	
	if (x>positionimage->x)
            {
                s=1;
                positionimage->x+=10;
            }
                
            else
            {
            	
            	init_pers(&image,screen,"2.png",*(positionimage));
        SDL_Flip(screen);
                s=2;
            	positionimage->x-=10;
            }
}

         
void clavier(SDL_Event event,SDL_Rect* positionimage,SDL_Surface *image,SDL_Surface *screen,SDL_Rect* positionscreen,SDL_Rect* positions)
{SDL_Surface *obstacle =NULL,*fond=NULL,*stone=NULL;
                switch(event.key.keysym.sym)
{
 case 
SDLK_LEFT:
init_pers(&image,screen,"2.png",*(positionimage));
SDL_Flip(screen);
positionimage->x-=40;
break;
case
SDLK_RIGHT:

positionimage->x+=40;
break;
case
SDLK_UP:
positionimage->y-=80;
init_pers(&fond,screen,"exp.png",*(positionscreen));
init_pers(&obstacle,screen,"obstacle.png",*(positionscreen));
init_pers(&stone,screen,"s.png",*(positions));
SDL_Flip(screen);
SDL_BlitSurface(image, NULL, screen,positionimage);
SDL_Flip(screen);
SDL_Delay(500);
positionimage->y+=80;
init_pers(&fond,screen,"exp.png",*(positionscreen));
init_pers(&obstacle,screen,"obstacle.png",*(positionscreen));
init_pers(&stone,screen,"s.png",*(positions));
SDL_Flip(screen);
SDL_BlitSurface(image, NULL, screen,positionimage);
SDL_Flip(screen);

break;
case SDLK_SPACE:
if (collision(positionimage,positions)==0)
{
positions->x+=200;
init_pers(&stone,screen,"s.png",*(positions));
SDL_Flip(screen);
}
default:
break;
}}

int collision(SDL_Rect* rect1,SDL_Rect* rect2)
{
        if(rect1->y >= rect2->y + rect2->h)
                return 0;
        if(rect1->x >= rect2->x + rect2->w)
                return 0;
        if(rect1->y + rect1->h <= rect2->y)
                return 0;
        if(rect1->x + rect1->w <= rect2->x)
                return 0;
        return 1;
}
