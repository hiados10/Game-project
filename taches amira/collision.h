#ifndef _COLLISION_H_
#define _COLLISION_H_

typedef struct collision
{
	SDL_Surface *bg_collision;
}collision;

SDL_Color recuperer_couleur(SDL_Surface *fond_collision,SDL_Rect position);
int verifier_collision(SDL_Surface *fond_collision,SDL_Rect position_camera,SDL_Rect position_voiture);

#endif
