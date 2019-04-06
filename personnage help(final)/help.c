#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <string.h>
#include "help.h"

void initialiser_persHelp( help * ph)
{ ph->position.x=50;
ph->position.y=100;
ph->status=0;//nonactivee
ph->personnage=IMG_Load("1.png");

}
void afficher_persHelp(help p)
{SDL_Event event;
SDL_Surface * screen;
screen = SDL_SetVideoMode(1600, 400, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    int continuer = 1;

initialiser_persHelp(&p);
   while (continuer)
    {
        SDL_PollEvent(&event); 
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
                break;
        }
 
 SDL_BlitSurface(p.personnage,NULL,screen,&p.position);
 SDL_Flip(screen);
    }
SDL_FreeSurface(screen);
    SDL_FreeSurface(p.personnage);
    SDL_Quit();


}
