#ifndef TACHE_H_INCLUDED
#define TACHE_H_INCLUDED
typedef struct {
	            SDL_Rect position;
	            SDL_Surface *imager[4],*imagel[4];
	            int stage,nbvie;
	            int s,m;  //son et music
	            char direction;
	            int enig1,enig2,enig3;
	           // horaire tempsr; //temps qui reste
	            float vitesse;
                

}player;
void init_pers(SDL_Surface** img,SDL_Surface* ecran,char place[],SDL_Rect pos);
void souris(SDL_Event event,SDL_Rect* positionimage,SDL_Surface *screen,SDL_Rect* positionscreen);
void clavier(SDL_Event event,SDL_Rect* positionimage,SDL_Surface *image,SDL_Surface *screen,SDL_Rect* positionscreen,SDL_Rect* positions);
int collision(SDL_Rect* rect1,SDL_Rect* rect2);
#endif