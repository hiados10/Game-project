#include <stdlib.h> 
#include <stdio.h> 
#include <SDL/SDL.h>
#include <SDL/SDL_image.h> 

int scrolling(SDL_Surface * ecran,SDL_Surface * stage,hero *h,SDL_Rect *posbg,char direction)
{

    int scroll=0;
    switch(direction)
    {
        case 'r' :
        if(h->posper.x>ecran->clip_rect.w/2)
        {
            scroll = 1;
            posbg->x=posbg->x+50;
        }
        break;
        case 'l':
        if(h->posper.x < ecran->clip_rect.w/2 && posbg->x > 0)
        {
            scroll=1;
            posbg->x=posbg->x-50;
        }

        break;
 }
    return scroll;
}
