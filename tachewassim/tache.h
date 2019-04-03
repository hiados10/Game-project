#ifndef TACHE_H_INCLUDED
#define TACHE_H_INCLUDED
void init_pers(SDL_Surface** img,SDL_Surface* ecran,char place[],SDL_Rect pos);
void souris(SDL_Event event,SDL_Rect* positionimage);
void clavier(SDL_Event event,SDL_Rect* positionimage,SDL_Surface *image,SDL_Surface *screen,SDL_Rect* positionscreen);
int collision(SDL_Rect pos1,SDL_Rect pos2);
#endif