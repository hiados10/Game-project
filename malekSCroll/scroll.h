#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include "SDL/SDL_image.h"
#ifndef MALEK_H_INCLUDED
#define MALEK_H_INCLUDED

void scroll(SDL_Surface* ecran,SDL_Surface * map,SDL_Surface* perso,SDL_Rect posmap,SDL_Rect posperso,SDL_Rect camera);

#endif
