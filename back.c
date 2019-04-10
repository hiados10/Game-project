#include <stdio.h>
#include <stdlib.h>
#include "/usr/include/SDL/SDL_image.h"
#include "/usr/include/SDL/SDL_mixer.h"
#include "/usr/include/SDL/SDL_ttf.h"
#include <string.h>
#include <SDL/SDL_ttf.h>


int main()
{

SDL_Surface*ecran=NULL,*bg=NULL;
SDL_Rect pos;
int done=1;
//ecran=SetVideoMode(2048,297,)
ecran=SDL_SetVideoMode(800,1200,32,SDL_HWSURFACE | SDL_DOUBLEBUF);
bg=SDL_LoadBMP("bg.png");
pos.x=0;
pos.y=0;
while(done)
{

SDL_BlitSurface(bg,NULL,ecran,&pos);
SDL_Flip(ecran);

SDL_Delay(8000);


}


SDL_QUIT;
}
