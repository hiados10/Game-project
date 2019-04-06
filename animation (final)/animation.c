#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <string.h>
#include "animation.h"

void set_clips(int WIDTH,int HEIGHT,SDL_Rect pr[],SDL_Rect pl[])
{int i;
for(i=0;i<3;i++) {
pr[i].x = WIDTH * i;
pr[i].y = 0;
pr[i].w = WIDTH;
pr[i].h = HEIGHT;
pl[i].x = WIDTH * i;
pl[i].y = HEIGHT;
pl[i].w = WIDTH;
pl[i].h = HEIGHT;
}


}

void animation(SDL_Rect tr[],SDL_Rect tl[],char ch)
{

SDL_Rect pos;
pos.x=500;
pos.y=200;
int done=0,i=0;
SDL_Event e;
SDL_Surface *ecran=NULL,*bg=NULL,*image=NULL;
ecran=SDL_SetVideoMode(1024,980,32,SDL_HWSURFACE | SDL_DOUBLEBUF);
bg=SDL_LoadBMP("background.bmp");
image=IMG_Load("index.jpeg");
while(!done)
{
while(SDL_PollEvent(&e))
{
switch(e.type)
{
case SDL_QUIT:
done=1;
break;
}
SDL_BlitSurface(bg,NULL,ecran,NULL);
if (ch=='r')
SDL_BlitSurface(image,&tr[i],ecran,&pos);
else if (ch=='l')
SDL_BlitSurface(image,&tl[i],ecran,&pos);
SDL_Delay(1000/30);
SDL_Flip(ecran);

i++;
if(i>=3)
i=0;





}}
SDL_FreeSurface(ecran);
SDL_FreeSurface(bg);

SDL_QUIT;
}
