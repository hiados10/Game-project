#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>



int main(int argc, char *argv[])
{
    SDL_Surface *ecran = NULL;
    SDL_Surface *vie1=NULL,*vie2=NULL,*vie3=NULL,*vie4=NULL,*vie5=NULL,*back=NULL;
    SDL_Event event;
    SDL_Rect positionvie1,positionvie2,positionvie3,positionvie4,positionvie5,positionback;
    int continuer = 1;
    SDL_Init(SDL_INIT_VIDEO);
    ecran = SDL_SetVideoMode(1200, 560, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption("Vie", NULL);
    SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
    vie1= IMG_Load("coeur 3.png");
    vie2 = IMG_Load("coeur 2.png");
    vie3 = IMG_Load("coeur 1.png");
    
    vie4 = IMG_Load("coeur.png");
    back= IMG_Load("bg.png");
    //SDL_SetColorKey(vie, SDL_SRCCOLORKEY, SDL_MapRGB(vie[i]->format, 32, 156, 0));
    positionvie1.x = 0;
    positionvie1.y = 0;
    positionvie2.x = 0;
    positionvie2.y = 0;
    positionvie3.x = 0;
    positionvie3.y = 0;
    positionvie4.x = 0;
    positionvie4.y = 0;
    positionback.x = 0;
    positionback.y = 0;
    SDL_BlitSurface(back, NULL, ecran, &positionback);
    //SDL_EnableKeyRepeat(100,100);
     while(continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
            continuer = 0;
            break;
            case SDL_KEYDOWN:
            switch(event.key.keysym.sym)
            {
                case SDLK_LEFT:
               SDL_BlitSurface(back,NULL, ecran,&positionback); 
               SDL_BlitSurface(vie1,NULL, ecran,&positionvie1); 

    SDL_Flip(ecran);
    SDL_FreeSurface(ecran); 



                break;

                case SDLK_RIGHT:
              SDL_BlitSurface(back,NULL, ecran,&positionback); 
             SDL_BlitSurface(vie2,NULL, ecran,&positionvie2);

 SDL_Flip(ecran);
    SDL_FreeSurface(ecran);                

                break;
                  
                case SDLK_DOWN:
SDL_BlitSurface(back,NULL, ecran,&positionback); 
                SDL_BlitSurface(vie3,NULL, ecran,&positionvie3);

 SDL_Flip(ecran);
    SDL_FreeSurface(ecran);     
           
                break;
             
                case SDLK_UP:
SDL_BlitSurface(back,NULL, ecran,&positionback); 
                SDL_BlitSurface(vie4,NULL, ecran,&positionvie4);
SDL_BlitSurface(vie5,NULL, ecran,&positionvie5);


 SDL_Flip(ecran);
    SDL_FreeSurface(ecran); 
               

                break;
                
                /*case SDLK_e:
SDL_BlitSurface(back,NULL, ecran,&positionback); 
                SDL_BlitSurface(vie5,NULL, ecran,&positionvie5);*/

  SDL_Flip(ecran);
    SDL_FreeSurface(ecran); 
              

                break;
}
}
}

    SDL_Quit();

    return EXIT_SUCCESS;
}

    
    
    
