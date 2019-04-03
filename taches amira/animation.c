#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <string.h>
#include "animation.h"
#include "personnage.h"

void set_clips(int WIDTH,int HEIGHT,personnage* p)
{   int i ;
    SDL_Rect clipsRight [4], clipsLeft[4];

    for(i=0;i<3;i++) {
        p->clipsRight[ i ].x = WIDTH * i;
        p->clipsRight[ i ].y = 0;
        p->clipsRight[ i ].w = WIDTH;
        p->clipsRight[ i ].h = HEIGHT;

        p->clipsLeft[ i ].x = WIDTH * i;
        p->clipsLeft[ i ].y = HEIGHT;
        p->clipsLeft[ i ].w = WIDTH;
        p->clipsLeft[ i ].h = HEIGHT;
}


void animation(personnage* p,int WIDTH,int HEIGHT)
{
    
    p->x += vitesse;

        if( p->x < 0 ) 
    {
        p->x = 0;
    }
    if( p->x + WIDTH > SCREEN_WIDTH ) 
    {
        p->x = SCREEN_WIDTH - WIDTH;
    }
if( p->vitesse < 0 )
    {
                p->direction = l;

        p->frame++;
    }
    //Si Cat bouge à droite
    else if( p->vitesse > 0 )
    {

        p->direction= r;

        
        p->frame++;
    }
    //Si Cat ne bouge plus
    else
    {
        //Restart the animation
        p->frame = 1;
    }
if( p->frame >= 3 )
    {
        p->frame = 0;
    }
         
if( p->direction == ‘r’)
    {
        apply_surface( p->x, SCREEN_HEIGHT - HEIGHT, p->image, screen, &p->clipsRight[ p->frame ] );
    }
    else if( direction == ‘l’ )
    {
        apply_surface( p->x, SCREEN_HEIGHT - HEIGHT, p->image, screen, &p->clipsLeft[ p->frame ] );
    }
}
