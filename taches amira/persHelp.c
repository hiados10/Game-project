
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <string.h>
#include "help.h"


void initialiser_persHelp( help * ph,SDL_Surface*screen)
{ ph->position.x=50;
    ph->position.y=100;
status=0 ;//nonactivee ;
ph->personnge=IMG_Load(nom);
}
void afficher_persHelp(help ph)
{SDL_Event event;

    int continuer = 1;
SDL_SetColorKey(E.image_enemy, SDL_SRCCOLORKEY, SDL_MapRGB(E.image_enemy->format, 0, 0, 255));
SDL_EnableKeyRepeat(10, 10);

   while (continuer)
    {
        SDL_PollEvent(&event); /* On utilise PollEvent et non WaitEvent pour ne pas bloquer le programme */
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
                break;
        }
 SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
    SDL_BlitSurface(ph->personnage NULL,ecran,&ph.position) ;
  SDL_Flip(screen);
    }

    SDL_FreeSurface(E.image_enemy);
    SDL_Quit();

   

}
