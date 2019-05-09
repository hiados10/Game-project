/**
* @file background.c
*/
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "fnc.h"
/**
* @brief To initialize the image .
* @param b the image
* @param url the name of the image
* @return image
*/
image init_image(char nameofpicture[100],int x,int y)
{
image image;
image.img=IMG_Load(nameofpicture);//load image
image.pos.x=x;//position x de bg
image.pos.y=y;//position y de bg
return image;
}
/**
* @brief To affiche the image of minimap.
* @param b the background
* @param url the image
* @return Nothing
*/
void affichage(SDL_Surface *ecran,image image)
{
SDL_BlitSurface(image.img,NULL,ecran,&image.pos);
}
/**
* @brief To free the background b .
* @param b the background
* @param url the url of the image
* @return Nothing
*/

void librer_image(image image)
{
 SDL_FreeSurface(image.img);//Liberer memoire
}


