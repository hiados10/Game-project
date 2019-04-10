#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include "SDL/SDL_image.h"
#include "scroll.h"

void scroll(SDL_Surface* ecran,SDL_Surface * map,SDL_Surface* perso,SDL_Rect posmap,SDL_Rect posperso,SDL_Rect camera)
{
SDL_Rect posaux;
posaux.y = posperso.y;
camera.x=posperso.x-150;
camera.y=0;
 
    if(camera.x<0)
    {
     camera.x=0;

     posaux.x = posperso.x;
     }
     else
     {
        posaux.x = 150;
     }

        SDL_BlitSurface(map, &camera, ecran, &posmap);
        SDL_BlitSurface(perso, NULL, ecran, &posaux);
        SDL_Flip(ecran);
      }
