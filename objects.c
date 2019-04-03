#include <stdlib.h>

#include <stdio.h>

#include "SDL/SDL.h"

#include "SDL/SDL_image.h"

#include "SDL/SDL_mixer.h"

int menu()

{
int continuer=1,x=1,i;
int event;
SDL_Event event;

    SDL_Surface *screen = NULL,*box = NULL;
SDL_Rect positionscreen,positionbox;

	positionbox.x=910;

	positionbox.y=110;

SDL_Surface* Loadscreen = NULL; 
SDL_Surface* optimizedImage = NULL;

Loadscreen = SDL_LoadBMP("Background.JPG" );
Loadbox = SDL_LoadBMP ("Box.JPG");


SDL_BlitSurface(image, NULL, screen, &positionimage);
screen = SDL_SetVideoMode( 256 , 224 , 32 , SDL_DOUBLEBUF|SDL_HWSURFACE|SDL_ANYFORMAT);
SDL_FillRect(screen , NULL , 0x221122);
SDL_Flip(screen);
SDL_Event event;

//______ MY____TRY______COLLISION_____//

int collision_right(SDL_Surface *s,SDL_Surface *masque,SDL_Rect *p,stage *stage1 )
{
    int x,y;
  SDL_Color ca;
  x=p->x +s->w+lvl1->pos.x;
  y=p->y +s->h/2;
  ca=get_pixel(masque,x,y);
        if((ca.b==255)&&(ca.r==255)&&(ca.g==255))
        {
           return 1;
        }
        else
        {
          return 0 ;
        }


