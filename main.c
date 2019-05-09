/**
* @file main.c
* @brief Testing Program.
* @author hichri
* @version 0.1
* @date Apr 01, 2015
*
* Testing program for mini map 
*
*/
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "fnc.h"

void main()
{
    int continuer=1;
    SDL_Event event;
    SDL_Surface *ecran =NULL;
    ecran= SDL_SetVideoMode(1000, 500, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    image map,character,minimap,icon;
    map=init_image("map.png",0,0);
    character=init_image("character.png",23,311);
    minimap=init_image("maptest.png",799,0);
    icon=init_image("icontest.png",804,60);
    while(continuer)
        {
        while(SDL_PollEvent(&event))
           {
            switch(event.type)
               {
                case SDL_QUIT:
                    continuer=0;
                break;
                case SDL_KEYDOWN:
                    switch(event.key.keysym.sym)
                           {
                        case SDLK_RIGHT:
                            if(character.pos.x < 940){
                                character.pos.x += 40;
                                icon.pos.x += 8;
                            }
                        break;
                        case SDLK_LEFT:
                            if(character.pos.x > 10)
                            {
                                character.pos.x -= 40;
                                icon.pos.x -= 8;
                            }
                        break;
                    }
                break;
                }
            }
        affichage(ecran,map); 
        affichage(ecran,character); 
        affichage(ecran,minimap); 
        affichage(ecran,icon); 
        SDL_Flip(ecran);
    }
    librer_image(map);
    librer_image(character);
    librer_image(minimap);
    librer_image(icon);

}
