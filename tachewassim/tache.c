#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "tache.h"
void init_pers(SDL_Surface** img,SDL_Surface* ecran,char place[20],SDL_Rect pos)
{SDL_Surface *obstacle =NULL,*fond;
    (*img) = IMG_Load(place);
    SDL_BlitSurface((*img), NULL, ecran, &pos);

}

void souris(SDL_Event event,SDL_Rect* positionimage)
{ 
	positionimage->x+=20;
}

void clavier(SDL_Event event,SDL_Rect* positionimage,SDL_Surface *image,SDL_Surface *screen,SDL_Rect* positionscreen)
{SDL_Surface *obstacle =NULL,*fond=NULL;
                switch(event.key.keysym.sym)
{
 case 
SDLK_LEFT:
init_pers(&image,screen,"2.png",*(positionimage));
SDL_Flip(screen);
positionimage->x-=40;
init_pers(&image,screen,"2.png",*(positionimage));
SDL_Flip(screen);
break;
case
SDLK_RIGHT:

positionimage->x+=40;
break;
case
SDLK_UP:
positionimage->y-=80;
init_pers(&obstacle,screen,"obstacle.png",*(positionscreen));
init_pers(&fond,screen,"exp2.png",*(positionscreen));

SDL_Flip(screen);
SDL_BlitSurface(image, NULL, screen,positionimage);
SDL_Flip(screen);
SDL_Delay(500);
positionimage->y+=80;
init_pers(&obstacle,screen,"obstacle.png",*(positionscreen));
init_pers(&fond,screen,"exp2.png",*(positionscreen));
SDL_Flip(screen);
SDL_BlitSurface(image, NULL, screen,positionimage);
SDL_Flip(screen);

break;
case
SDLK_DOWN:
positionimage->y+=40;
break;
default:
break;
}
int collision(SDL_Rect pos1,SDL_Rect pos2)
{
       if( (pos1.x+pos1.w<pos2.x) || (pos1.x>pos2.x+pos2.w) || (pos1.y+pos1.h<pos2.y) || (pos1.y>pos2.y+pos2.h) )
        return 1;
    else
        return 0;
}

}