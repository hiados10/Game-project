#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include "play.h"
//void loadgame(SDL_Surface* screen,Mix_Music *musique,Mix_Chunk *son,char* nom_de_fichier);
void jouer_son(Mix_Music *musique,int k);
void exit_game(SDL_Surface *ecran,Mix_Music *musique,Mix_Chunk *button,int *k,int *continuer,int s);
void change1(SDL_Surface *ecran,int k,int* x, int* y,int s,Mix_Chunk *button);
void setting(SDL_Surface *ecran,Mix_Music *musique,Mix_Chunk *button,int *k,int *s,int* x,int* y,int* x1,int* y1);
void input(int* x,int* y,int* x1,int* y1,SDL_Surface *ecran,int k,int s,Mix_Music *musique,Mix_Chunk *button);
void play (SDL_Surface* screen,Mix_Music *musique,Mix_Chunk *button,int k,int x,int y,int x1,int y1,char* nom_de_fichier,int s);
void onep(SDL_Surface* screen,Mix_Music *musique,Mix_Chunk *button,int k,int x,int y,char* nomfich,int s);
void newgame (SDL_Surface* screen,Mix_Music *musique,Mix_Chunk *button,int k,int x,int y,int x1,int y1,char* nomfich,int s);
void loadgame(SDL_Surface* screen,Mix_Music *musique,Mix_Chunk *button,char* nomfich,player* p,int* posx,int* posy,int* choix,int* s);
#endif
/**
@file [menu.c]
@file [main.c]
*/
