#ifndef OBJECTS_H_INCLUDED
#define OBJECTS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

typedef struct lvl lvl ;
struct lvl
 {
SDL_Surface *background [3];
SDL_Surface *objects [30]
};


typedef struct save save;
struct save
{
int lives;
int score;
int pos_p_x;
int pos_p_y;
int lvl;
int direction;
int pos_enemy_x;
int pos_enemy_y;
int pos_perso_x;
int pos_perso_y;
int scrol_x;
int scrol_y;
};

typedef struct stage stage;
struct stage
{
     int niv;
    SDL_Surface *screen;
    SDL_Surface *object;
    SDL_Rect position;
    SDL_Event event;
   int saves;
};

int collision_right(SDL_Surface *s,SDL_Surface *masque,SDL_Rect *p,lvl *lvl1);
int collision_left(SDL_Surface *s,SDL_Surface *masque,SDL_Rect *p,lvl *lvl1);
int Collision(SDL_Rect box);
void initialiser_lvl(stage *lvl1);

#endif // OBJECTS_H_INCLUDED


SDL_Surface *load_image(SDL_Surface *image,SDL_Rect p,char ch[]);
SDL_Color get_pixel(SDL_Surface *p,int x ,int y );
