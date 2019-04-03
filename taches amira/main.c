#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include <SDL/SDL_ttf.h>
#include <string.h>
#include "help.h"


int main ()
{
SDL_Surface * screen;
SDL_Rect positionecr;
SDL_Event event;
char pause;
int done=1;
help h;
SDL_Init(SDL_INIT_VIDEO);
screen=SDL_SetVideoMode (640,480,32,SDL_HWSURFACE | SDL_DOUBLEBUF);

initialiser_persHelp(&h);
afficher_persHelp(h,screen);
return 0;
}
