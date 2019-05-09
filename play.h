#ifndef PLAY_H_INCLUDED
#define PLAY_H_INCLUDED
/**
* @struct player
* @brief struct for player
*/
typedef struct {
	            SDL_Rect position; /*!< position*/
	            SDL_Surface *imager[4],*imagel[4];/*!< les images*/
	            int stage,vie;/*!< num du stage et nombre des vies*/
	            int s,m;  //son et music
	            char direction;/*!< direction*/
	            int enig1,enig2,enig3;
	           // horaire tempsr; //temps qui reste
	            float vitesse;
                     int x,y;/*!< choix des touches*/
                

}player;

/**
* @struct temps
* @brief struct for time
*/
typedef struct temps
{
	int commencer;/*!< debut du temps*/
	int temps_stage1;/*!< temps restant*/
	
}temps;

void loadstage1(SDL_Surface *ecran,player p,char* nomfich,int choix,int x,int y,int s,int k,Mix_Music *musique);
void initload(int choix,player *p);


int scrolling(SDL_Surface * ecran,SDL_Surface * stage,player *h,SDL_Rect *posbg,char direction);


SDL_Color recuperer_couleur(SDL_Surface *fond_collision,SDL_Rect position);
int verifier_collision(SDL_Surface *fond_collision,SDL_Rect position_pers,SDL_Rect position_camera);

void sauvegarder(char *nom_de_fichier,player p,SDL_Rect pos,int choix,int s);
void temps_jeu(temps *t);
void compter_temps_stage1(temps *t);
int convertir_milliseconde(int temps_milli);
void afficher_temps(temps t,SDL_Surface* ecran,int stage);


void initialiserp(int choix,player* p,int x,int y);
void recuperer_touch(int tab[],SDL_Event press,int x,int y);
void animation(SDL_Surface* ecran,player* p,SDL_Surface* bg,SDL_Rect position,SDL_Rect positions);
void stage1(SDL_Surface* ecran, int k,int choix,int x,int y,char* nomfich,Mix_Music *musique);




#endif

/**
@file [play.c]
@file [main.c]
*/
