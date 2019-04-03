#ifndef _HELP_H_
#define _HELP_H_
typedef struct help
{
	SDL_Surface * personnage;
	SDL_Rect position;
	
	int status;
}help;

void initialiser_persHelp( help * ph);
void afficher_persHelp(help ph,SDL_Surface*screen);

#endif
