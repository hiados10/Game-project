#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <string.h>
#include "menu.h"
#include "play.h"

int arduinoWriteData(int x)
{
    char chemin[]="/dev/ttyACM0";
    FILE*f;

    f=fopen(chemin,"w");
    if(f == NULL)
        return(-1);

    fprintf(f,"%d",x);
    fclose(f);

    return(0);
}



int arduinoReadData(int x[])
{
    char chemin[]="/dev/ttyACM0";
    FILE*f;
    char c;
    f=fopen(chemin,"r");

    if(f == NULL)
        return(-1);

     else if(f!=NULL)
    {
        if(!feof(f))
        {
            fscanf(f,"%d %d",&x[0],&x[1]);
            printf("i'm reading\n");
        }

    }
    else return EXIT_FAILURE;

    fclose(f);

    return(0);
}



/**
*@file main.c
*@brief Testing Program.
*@author amira
*@version 1
*@date Apr 15,2019
*
*

*/
int main()
{
char nomfich[]="save.txt";

SDL_Surface *screen = NULL,*image1 = NULL,*image3 = NULL,*image[3]={NULL},*new=NULL,*load=NULL,*anim[3]={NULL};
Mix_Chunk *button;
int but=0,k=1,continuer=1,i,s=1,x=1,y=1,x1=1,y1=1;
SDL_Event event;
if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
{printf("%s",Mix_GetError());
}
button=Mix_LoadWAV("buttonsound.wav");
Mix_Music *music;
music=Mix_LoadMUS("night.mp3");
    SDL_Rect positionscreen,positionimage1,positionimage[3];



    positionimage1.x=0;

    positionimage1.y=0;

   positionimage[0].x=910;

    positionimage[0].y=110;
positionimage[1].x=940;

    positionimage[1].y=195;

positionimage[2].x=960;

    positionimage[2].y=270;
/*positionimage[3].x=980;


    positionimage[3].y=360;
positionimage[4].x=1000;

    positionimage[4].y=440;*/

    positionscreen.x = 0;

    positionscreen.y = 0;
SDL_Init(SDL_INIT_VIDEO);

screen = SDL_SetVideoMode(1280, 720, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
SDL_Flip(screen);
image1 = IMG_Load("1.jpg"); //bg

jouer_son(music,k); //fonction a devlopper

    SDL_BlitSurface(image1,NULL,screen,&positionimage1);
SDL_Flip(screen);
//Mix_PlayMusic(music, -1);
   image[0] = IMG_Load("a.png");

image[1]= IMG_Load("b.png");

image[2]= IMG_Load("e.png");

//image[3] = IMG_Load("d.png");

//image[4] = IMG_Load("e.png");
anim[0]=IMG_Load("option/ban/an.png");
anim[1]=IMG_Load("option/ban/bn.png");
anim[2]=IMG_Load("option/ban/en.png");


int sar[2],sprev=1;

    for(i=0; i<3; i++)
    {
        SDL_BlitSurface(image[i], NULL, screen, &positionimage[i]);

    }
SDL_Flip(screen);

    while (continuer)
    {arduinoWriteData(1);
    sprev=sar[0];
       
        arduinoReadData(sar);
        //printf("s0=%d\n", s[0]);
        //printf("b=%d\n", s[1]);


       
            if(sar[0]==0 && sprev!=0)
            {
                but--;
            }
            if(sar[0]==2 && sprev!=2)
            {
                but++;
            }

            if(sar[1]==1)
            {
                if(but=3)
                   { if (s==1)
                   Mix_PlayChannel(-1,button,0);
                    exit_game(screen,music,button,&k,&continuer,s);}
                else if(but==2)
                    { if (s==1)
                   Mix_PlayChannel(-1,button,0);
                    setting(screen,music,button,&k,&s,&x,&y,&x1,&y1);
                }


                else if(but==1)
                {
                    if (s==1)
                  Mix_PlayChannel(-1,button,0);
                    play(screen,music,button,k,x,y,x1,y1,nomfich,s);

                }
                
            }
                if (but>3)
                 but=0;
                 if(but<0)
                     but=3;
        
        
            SDL_WaitEvent(&event);
        
switch(event.type)
{case SDL_QUIT:
continuer = 0;
break;

case SDL_KEYDOWN:
            switch(event.key.keysym.sym)
            {
            case SDLK_UP:
              if (s==1)
             arduinoWriteData(0);
              Mix_PlayChannel(-1,button,0);
                but--;
                break;
            case SDLK_DOWN:
                  arduinoWriteData(2);
                 if (s==1)
              Mix_PlayChannel(-1,button,0);
                but++;
                break;
            case SDLK_RETURN:
                if(but==3)
                { if (s==1)
                   Mix_PlayChannel(-1,button,0);
                    exit_game(screen,music,button,&k,&continuer,s);}

                else if(but==2)
                { if (s==1)
                   Mix_PlayChannel(-1,button,0);
                    setting(screen,music,button,&k,&s,&x,&y,&x1,&y1);
                }
                else if(but==1)
                { 
                   if (s==1)
                  Mix_PlayChannel(-1,button,0);
                    play(screen,music,button,k,x,y,x1,y1,nomfich,s);

                }
                
                break;
            }
            if (but>3)
                 but=0;
                 if(but<0)
                     but=3;
            break;
case SDL_MOUSEBUTTONDOWN:
            if (event.button.button==SDL_BUTTON_LEFT)
            {
if(event.button.x > 910 && event.button.x <1114 && event.button.y> 110 && event.button.y <160)
{

but=1;
//new_game(screen,music,button,&k,&j,"21.png");
play(screen,music,button,k,x,y,x1,y1,nomfich,s);
                    jouer_son(music,k);

}


else if(event.button.x > 940 && event.button.x <1150 && event.button.y> 195 && event.button.y <250)
{
but=2;
setting(screen,music,button,&k,&s,&x,&y,&x1,&y1);

}
else if(event.button.x > 960 && event.button.x <1175 && event.button.y> 270 && event.button.y <320)
{
but=3;
exit_game(screen,music,button,&k,&continuer,s);
}
/*else if(event.button.x > 980 && event.button.x <1190 && event.button.y> 360 && event.button.y <410)
{x=4;
image3 = IMG_Load("7.png");

}

else if(event.button.x > 1000 && event.button.x <1210 && event.button.y> 440 && event.button.y <490)
{Mix_PlayChannel(1,button,0);
but=5;
exit_game(screen,music,button,&k,&continuer);
} */break;
            }
case SDL_MOUSEMOTION:
        {
            if (event.motion.x > 910 && event.motion.x < 1114 && event.motion.y>110 && event.motion.y<160)
                {if (s==1)
              Mix_PlayChannel(-1,button,0);


                    but=1;


                }
                else if(event.motion.x > 940 && event.motion.x < 1150 && event.motion.y>195 && event.motion.y<250)
                    {if (s==1)
              Mix_PlayChannel(-1,button,0);
                    but=2;
                   }
                 else if(event.motion.x > 960 && event.motion.x <1175 && event.motion.y>270 && event.motion.y<320)
                    {if (s==1)
              Mix_PlayChannel(-1,button,0);
                    but=3;
                   }
                 else but=0;


          break;
        }





}
SDL_BlitSurface(image1,NULL,screen,&positionimage1);
SDL_Flip(screen);
if(but==1)
                    {
                        
                        SDL_BlitSurface(anim[0], NULL, screen, &positionimage[0]);
                           for(i=1; i<3; i++)
    {
        SDL_BlitSurface(image[i], NULL, screen, &positionimage[i]);

    }
                        SDL_Flip(screen);

                    }
                    else if(but==2){
                         SDL_BlitSurface(image[0], NULL, screen, &positionimage[0]);
                        SDL_BlitSurface(image[2], NULL, screen, &positionimage[2]);
                        SDL_BlitSurface(anim[1], NULL, screen, &positionimage[1]);
                        SDL_Flip(screen);

                    }
                  else if(but==3){ for(i=0; i<2; i++)
    {
        SDL_BlitSurface(image[i], NULL, screen, &positionimage[i]);

    }
                         
                        SDL_BlitSurface(anim[2], NULL, screen, &positionimage[2]);
                        SDL_Flip(screen);

                    }
                   else{
                         
                         for(i=0; i<3; i++)
    {
        SDL_BlitSurface(image[i], NULL, screen, &positionimage[i]);

    }
                        SDL_Flip(screen);

                    }

                    
}





















      SDL_FreeSurface(image1);
    for(i=0; i<3; i++)
    {
        SDL_FreeSurface(image[i]);

    }
     for(i=0; i<3; i++)
    {
        SDL_FreeSurface(anim[i]);

    }



    Mix_FreeChunk(button);
    Mix_FreeMusic(music);

    Mix_CloseAudio();


    
    SDL_Quit();
return 0;}
