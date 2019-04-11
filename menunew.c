#include <stdlib.h>

#include <stdio.h>

#include "SDL/SDL.h"

#include "SDL/SDL_image.h"

#include "SDL/SDL_mixer.h"

int menu(SDL_Surface *screen,int * music,int *sound)
{
    SDL_Event event;
    char chemin[100];
    int continuer=1, choix=1, i, j ,x ,y ,s=0;
        Mix_Chunk* button;
    SDL_Rect positionFond;
    positionFond.x=0;
    positionFond.y=0;
    SDL_Surface *background, *bouton[5][1];
    background=IMG_Load("background.png");
    button = Mix_LoadWAV("buttonsound.wav");
    for (i=0;i<5;i++)
    {
        for (j=0;j<1;j++)
        {
            if (i==2&&j>1)
                bouton[i][j]=NULL;
            else
            {
                sprintf(chemin,"123/%d%d.png", i+1, j+1);
                bouton[i][j]=IMG_Load(chemin);
            }
        }
    }
    while(continuer)
    {
        SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,0,0,0));
        SDL_BlitSurface(background,NULL,screen,&positionFond);
        if (choix==1)
            SDL_BlitSurface(bouton[0][*music],NULL,screen,&positionFond);
        else
            SDL_BlitSurface(bouton[0][*music+2],NULL,screen,&positionFond);
        if (choix==2)
            SDL_BlitSurface(bouton[1][*sound],NULL,screen,&positionFond);
        else
            SDL_BlitSurface(bouton[1][*sound+2],NULL,screen,&positionFond);
        if (choix==3)
            SDL_BlitSurface(bouton[2][1],NULL,screen,&positionFond);
        else
            SDL_BlitSurface(bouton[2][2],NULL,screen,&positionFond);
        if (choix==4)
            SDL_BlitSurface(bouton[3][1],NULL,screen,&positionFond);
        else
            SDL_BlitSurface(bouton[3][2],NULL,screen,&positionFond);
        if (choix==5)
            SDL_BlitSurface(bouton[4][1],NULL,screen,&positionFond);
        else
            SDL_BlitSurface(bouton[4][2],NULL,screen,&positionFond);
        SDL_Flip(screen);
        while(SDL_PollEvent(&event))
        {
            switch(event.type)
            {
                case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
                    case SDLK_DOWN:
                    if (*sound)
            Mix_PlayChannel(1,button,0);
                    if (choix==5)
                        choix=1;
                    else
                        choix++;
                    break;
                    case SDLK_UP:
                    if (*sound)
            Mix_PlayChannel(1,button,0);
                    if (choix==1)
                        choix=5;
                    else
                        choix--;
                    break;
                    case SDLK_RETURN:
                    
                         continuer=0;
                    
                    break;
                }
                break;
                case SDL_MOUSEMOTION:
             SDL_GetMouseState(&x,&y);
            if (y>910&& y<385 && x>910 && x<1114)
            {
                choix=1;
                 if (!s&&sound)
                {
                  Mix_PlayChannel(-1,button,0);
                    s=1;
                }
            }
            else if (y>195 && y<250 && x>940 && x<1150)
            {
                choix=2;
                 if (!s&&sound)
                {
                  Mix_PlayChannel(-1,button,0);
                    s=1;
                }
            }
             else if (y>270 && y<320 && x>960 && x<1175)
            {
                choix=3;
                 if (!s&&sound)
                {
                  Mix_PlayChannel(-1,button,0);
                    s=1;
                }
            }
	    else if (y>360 && y<410 && x>980 && x<1190)
            {
                choix=4;
                 if (!s&&sound)
                {
                  Mix_PlayChannel(-1,button,0);
                    s=1;
                }
            }
		else if (y>440 && y<490 && x>1000 && x<1210)
            {
                choix=5;
                 if (!s&&sound)
                {
                  Mix_PlayChannel(-1,button,0);
                    s=1;
                }
            }
            else
            {
                s=0;
            }
            break;
            case SDL_MOUSEBUTTONUP:
            
                        continuer=0;
                        break;
                    
              
            }
        }
    }
 
 
    Mix_FreeChunk(button);
    SDL_FreeSurface(background);
    for (i=0;i<5;i++)
    {
        for (j=0;j<1;j++)
        {
            if (bouton[i][j]!=NULL)
                SDL_FreeSurface(bouton[i][j]);
        }
    }

    }
int main()
{
SDL_Surface *screen = NULL;
Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024);
SDL_Init(SDL_INIT_EVERYTHING);
screen = SDL_SetVideoMode(1900, 1050, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
int choix;
Mix_Music* night=NULL;
night=Mix_LoadMUS("night.mp3");
Mix_PlayMusic(night,-1);

do
{
choix=menu(screen,);
switch(choix)
{
case 1:
printf("play");
break;
case 2:
printf("settings");
break;
case 3:
printf("leaderboard");
break;
case 4:
printf("achievement");
break;
}
}
while (choix!=5);

SDL_Quit();
Mix_FreeMusic(night);
Mix_CloseAudio();
return 0; 
}
int play(SDL_Surface *screen, int *music, int *sound)
{
}
