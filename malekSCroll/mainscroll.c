#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include "SDL/SDL_image.h"
#include "scroll.h"

int main(int argc, char *argv[])
{
 
    SDL_Surface *ecran=NULL,*map=NULL,*perso=NULL;
    SDL_Rect posmap,camera,posperso,posaux;
    SDL_Event event;
    int continuer = 1;
 
 
    SDL_Init(SDL_INIT_VIDEO);
 
    ecran = SDL_SetVideoMode(400, 400, 32, SDL_HWSURFACE);
 
    perso = IMG_Load("right.png");
    map=SDL_LoadBMP("bg.bmp");
 
    posmap.x=0;
    posmap.y=0;
 
    posperso.x=150;
    posperso.y=150;
 
    
camera.h=400;
    camera.w=400;
 
    SDL_BlitSurface(map, &camera, ecran, &posmap);
    SDL_BlitSurface(perso, NULL, ecran, &posperso);
    SDL_Flip(ecran);
 
    SDL_EnableKeyRepeat(10, 10);
 
    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
                break;
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
                    case SDLK_RIGHT: // Flèche droite
                    posperso.x++;
                        break;
                    case SDLK_LEFT: // Flèche gauche
                         posperso.x--;
                        break;
                }
                break;
}
scroll( ecran,map,perso,posmap,posperso,camera);
 
        

 }
    SDL_FreeSurface(map);
    SDL_FreeSurface(perso);
    SDL_Quit();
 
    return EXIT_SUCCESS;
}







