#include <stdlib.h>

#include <stdio.h>

#include "SDL/SDL.h"

#include "SDL/SDL_image.h"

#include "SDL/SDL_mixer.h"
#include "tache.h"
#include <time.h>
#include <unistd.h>


 

int main(void)

{char pause;
int boucle=1;
int done=1;
    SDL_Surface *screen = NULL,*obstacle =NULL, *image = NULL,*fond,*stone;
int *X,*Y;
    SDL_Rect positionscreen, positionimage,positions;
    int mouseX,mouseY;
    
    SDL_Event event;
positions.x=480;
positions.y=630;
positions.w=72;
positions.h=85;
    positionimage.x=40;

    positionimage.y=570;
    positionimage.w=57;
    positionimage.h=145;

    positionscreen.x = 0;

    positionscreen.y = 0;
    

Mix_Music *music;
   



if(SDL_Init(SDL_INIT_VIDEO)!=0)
{printf("unable to initialize SDL: %s\n",SDL_GetError());
return 1;}
screen = SDL_SetVideoMode(1280, 720, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);

if (screen == NULL){
printf("unable to set video mode: %s\n",SDL_GetError());
return 1;}
init_pers(&fond,screen,"exp.png",positionscreen);
init_pers(&image,screen,"1.png",positionimage);
init_pers(&obstacle,screen,"obstacle.png",positionscreen);
init_pers(&stone,screen,"s.png",positions);

if(image == NULL)
{printf("unabl to load bitmap: %s\n",SDL_GetError());
return 1;}
SDL_Flip(screen);

while(boucle)
{

SDL_FreeSurface(fond);
SDL_FreeSurface(obstacle);
while(done)
{SDL_PollEvent(&event);
switch(event.type)
{
case SDL_QUIT:
done=0;
break;
case SDLK_ESCAPE:
done=0;
break;
case SDL_KEYDOWN:
clavier(event,&positionimage,image,screen,&positionscreen,&positions);
break;
case SDL_MOUSEBUTTONUP:
souris(event,&positionimage,screen,&positionscreen);
break;
default:
break;}
init_pers(&fond,screen,"exp.png",positionscreen);
init_pers(&image,screen,"1.png",positionimage);
init_pers(&obstacle,screen,"obstacle.png",positionscreen);
init_pers(&stone,screen,"s.png",positions);
/*fond =IMG_Load("exp.png");
obstacle=IMG_Load("obstacle.png");
image = IMG_Load("1.png");
SDL_BlitSurface(fond, NULL, screen, &positionscreen);
SDL_BlitSurface(obstacle, NULL, screen, &positionscreen);
SDL_BlitSurface(image, NULL, screen, &positionimage);*/
SDL_Flip(screen);
}}
SDL_FreeSurface(fond);
SDL_FreeSurface(image);
SDL_FreeSurface(obstacle);

SDL_Quit:
pause=getchar();


return 0;
}