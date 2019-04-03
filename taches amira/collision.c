#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <string.h>
#include "collision.h"

SDL_Color recuperer_couleur(SDL_Surface *fond_collision,SDL_Rect position)
{
    SDL_Color couleur;
    Uint32 coul =0;

    char* Pposition = fond_collision->pixels;

    Pposition+=fond_collision->pitch *position.y;
    Pposition+=fond_collision->format->BytesPerPixel *position.x;
    memcpy(&coul,Pposition, fond_collision->format->BytesPerPixel);
    SDL_GetRGB(coul,fond_collision->format,&couleur.r,&couleur.g,&couleur.b);

    //printf("couleur recuperee\n");

    return couleur;
}

int verifier_collision(SDL_Surface *fond_collision,SDL_Rect position_camera,SDL_Rect position_voiture)
{


    SDL_Color couleur_col;
    SDL_Color couleur_recupere1;
    SDL_Color couleur_recupere2;
    SDL_Color couleur_recupere3;
    SDL_Color couleur_recupere4;

    SDL_Rect position1,position2,position3,position4,position;
    int largeur=294,hauteur=211,bord=100;

    position.x=position_camera.x+position_voiture.x;
    position.y=position_camera.y+position_voiture.y;

    position1.x=position.x+(largeur/2);
    position1.y=position.y+bord;

    position2.x=position.x+largeur-bord;
    position2.y=position.y+(hauteur/2);

    position3.x=position.x+(largeur/2);
    position3.y=position.y+hauteur-bord;

    position4.x=position.x+bord;
    position4.y=position.y+(hauteur/2);


    couleur_col.r=255;
    couleur_col.g=255;
    couleur_col.b=255;

    couleur_recupere1=recuperer_couleur(fond_collision,position1);
    couleur_recupere2=recuperer_couleur(fond_collision,position2);
    couleur_recupere3=recuperer_couleur(fond_collision,position3);
    couleur_recupere4=recuperer_couleur(fond_collision,position4);


    if(couleur_col.r==couleur_recupere1.r&&couleur_col.g==couleur_recupere1.g&&couleur_col.b==couleur_recupere1.b)
    {
        //printf("collision\n");
        return 1;
    }
    if(couleur_col.r==couleur_recupere2.r&&couleur_col.g==couleur_recupere2.g&&couleur_col.b==couleur_recupere2.b)
    {
        
        return 1;
    }
    if(couleur_col.r==couleur_recupere3.r&&couleur_col.g==couleur_recupere3.g&&couleur_col.b==couleur_recupere3.b)
    {
        return 1;
    }
    if(couleur_col.r==couleur_recupere4.r&&couleur_col.g==couleur_recupere4.g&&couleur_col.b==couleur_recupere4.b)
    {
        return 1;
    }

    return 0;
}
