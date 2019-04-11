#include <stdlib.h>
#include <stdio.h>

#include "SDL/SDL.h"

#include "SDL/SDL_image.h"

#include "SDL/SDL_mixer.h"



 

int main(int argc ,char *argv[])

{
int continuer=1,x=1,i;
SDL_Event event;

    SDL_Surface *screen = NULL,*image99=NULL,*image = NULL,*image3 = NULL,*imagea = NULL,*imageb = NULL,*imagec = NULL,*imaged = NULL,*imagee = NULL,*new=NULL,*load=NULL;
Mix_Chunk *button;
button=Mix_LoadWAV("button.wav");
Mix_Music *music;
    SDL_Rect positionscreen,positionimage,positionimagea,positionimageb,positionimagec,positionimaged,positionimagee;

    positionimage.x=0;

    positionimage.y=0;

positionimagea.x=910;

    positionimagea.y=110;
positionimageb.x=940;

    positionimageb.y=195;

positionimagec.x=960;

    positionimagec.y=270;
positionimaged.x=980;


    positionimaged.y=360;
positionimagee.x=1000;

    positionimagee.y=440;

    positionscreen.x = 0;

    positionscreen.y = 0;

int pos=0;

SDL_Init(SDL_INIT_VIDEO);

screen = SDL_SetVideoMode(1280, 720, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);


image99= IMG_Load("13.png");

image = IMG_Load("1.jpg");

imagea = IMG_Load("a.png");

imageb = IMG_Load("b.png");

imagec = IMG_Load("c.png");

imaged = IMG_Load("d.png");

imagee = IMG_Load("e.png");
if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)// initiliser mixer
    {
        printf("%s",Mix_GetError());
    }
    Mix_Music *musique;//pointeur musique jeux
    Mix_AllocateChannels(20);//
    musique = Mix_LoadMUS("night.mp3");//musique jeux
    Mix_PlayMusic(musique, -1);//repeter la music de jeux (boucle infinie)
    Mix_VolumeMusic(MIX_MAX_VOLUME / 1);//MIX_MAX_VOLUME se defere de chaque pc (peut etre 1 ou 2 selement)
    Mix_Chunk *MB;//pointeur music boutton(chunk se defere de formart) chunk pour format wav ; Music pour format mp3
    MB = Mix_LoadWAV("button.wav");

while(continuer==1)
{
SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,0,0,0));
SDL_BlitSurface(image,NULL,screen,&positionscreen);
SDL_BlitSurface(image, NULL, screen, &positionimage);
SDL_BlitSurface(imagea, NULL, screen, &positionimagea);
SDL_BlitSurface(imageb, NULL, screen, &positionimageb);
SDL_BlitSurface(imagec, NULL, screen, &positionimagec);
SDL_BlitSurface(imaged, NULL, screen, &positionimaged);
SDL_BlitSurface(imagee, NULL, screen, &positionimagee);
SDL_BlitSurface(image3, NULL, screen, &positionimage);


//displayButtons(screen);
SDL_Flip(screen);
SDL_PollEvent(&event);
switch(event.type)
{case SDL_QUIT:
continuer = 0;
break;
case SDL_KEYDOWN:
{
switch(event.key.keysym.sym)
 break ;
{
 case SDLK_BACKSPACE:

  image = IMG_Load("1.jpg");
  


}
break;
}

case SDL_MOUSEBUTTONUP:
if(event.button.x > 910 && event.button.x <1114 && event.button.y> 110 && event.button.y <160)
{
if(event.button.button==SDL_BUTTON_LEFT)
{
x=1;
while(x)
{
image3 = IMG_Load("15.png");
SDL_BlitSurface(image3, NULL, screen, 0);
image33 = IMG_Load("e.png");
SDL_BlitSurface(image, NULL, screen, 0);
SDL_Flip(screen);
switch(event.type){
case SDL_MOUSEBUTTONUP:
if(event.button.x > 0 && event.button.x <200 && event.button.y> 0 && event.button.y <160)
x=0;
break;
}}
}
if(event.button.x > 484 && event.button.x <796 && event.button.y> 240 && event.button.y <300)
{if(event.button.button==SDL_BUTTON_LEFT)
{
image3 = IMG_Load("13.png");
SDL_BlitSurface(image3, NULL, screen, 0);
SDL_Flip(screen);
}
}}}
if(event.button.x > 484 && event.button.x <800 && event.button.y> 200 && event.button.y <300)
{
if(event.button.button==SDL_BUTTON_LEFT)
{

image = IMG_Load("16.png");
SDL_BlitSurface(image, NULL, screen, &positionimage);
SDL_Flip(screen);
}
}
if(event.button.x > 487 && event.button.x <805 && event.button.y> 345 && event.button.y <395)
{
if(event.button.button==SDL_BUTTON_LEFT)
{
load= IMG_Load("17.png");
SDL_BlitSurface(load, NULL, screen, &positionimage);
SDL_Flip(screen);
}
}
if(event.button.x > 940 && event.button.x <1150 && event.button.y> 195 && event.button.y <250)
{
x=2;
image3 = IMG_Load("21.png");

}
 if(event.button.x > 960 && event.button.x <1175 && event.button.y> 270 && event.button.y <320)
{Mix_PlayChannel(1,button,0);
x=3;
image3 = IMG_Load("7.png");
}
 if(event.button.x > 980 && event.button.x <1190 && event.button.y> 360 && event.button.y <410)
{x=4;
image3 = IMG_Load("1.png");

}
 if(event.button.x > 1000 && event.button.x <1210 && event.button.y> 440 && event.button.y <490)
{
x=5;
image3 = IMG_Load("19.png");
if(event.button.x > 0 && event.button.x <1200 && event.button.y> 0 && event.button.y <600)
{
if(event.button.button==SDL_BUTTON_LEFT)
{
continuer=0;

}
}
} break;






              /*  if(i==1)
                {
                    x=1;
                }
                if(i==2)
                {
                    x=2;
                }
                if(i==3)
                {

                    x=3;

                }
                if(i==4)
                {
                    x=4;
                }

 		if(i==5)
                {
                    x=5;
                }
                break;
            }
*/










SDL_BlitSurface(image, NULL, screen, &positionimage);
SDL_BlitSurface(imagea, NULL, screen, &positionimagea);
SDL_BlitSurface(imageb, NULL, screen, &positionimageb);
SDL_BlitSurface(imagec, NULL, screen, &positionimagec);
SDL_BlitSurface(imaged, NULL, screen, &positionimaged);


SDL_BlitSurface(imagee, NULL, screen, &positionimagee);


SDL_BlitSurface(image3, NULL, screen, &positionimage);
SDL_Flip(screen);
}}
SDL_FreeSurface(image);
SDL_FreeSurface(imagea);
SDL_FreeSurface(imageb);
SDL_FreeSurface(imagec);
SDL_FreeSurface(imaged);
SDL_FreeSurface(imagee);
SDL_FreeSurface(image3);
SDL_Quit();
return 0 ;
}
