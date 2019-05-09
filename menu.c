/**
* @file menu.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <string.h>
#include "play.h"
/**
*@file menu.c
*/


/**
*@brief jouer son.
*@param musique 
*@param son
*@param k activation ou desactivation du musique
*@return Nothing
*

*/
void jouer_son(Mix_Music *musique,int k)
{

    //Mix_AllocateChannels(32); //Allouer 32 canaux
  if (k==1)
    {//Mix_Volume(1, MIX_MAX_VOLUME/2); //Mettre à mi-volume le post 1
    Mix_PlayMusic(musique, -1); }//Jouer infiniment la musique
    //Mix_VolumeMusic(MIX_MAX_VOLUME /(10/(k)));
    //Mix_VolumeChunk(son, MIX_MAX_VOLUME/(10/(k))); //Mettre un volume pour ce wav
 else if (k==0)
   Mix_HaltMusic();

}






int arduinoReadDataEx(int x[])
{   char chemin[]="/dev/ttyACM0";
    FILE*f;
    //char c;
    f=fopen(chemin,"r");

    printf(" arduino read Exit \n");

    if(f!=NULL)
    {
        if(!feof(f))
        {
            fscanf(f,"%d,%d",&x[0],&x[1]);
            printf("i'm reading\n");
        }

    }
    else return EXIT_FAILURE;


    //  fclose(f);

    return(0);
}






/**
*@brief interface exit.
*@param ecran  
*@param musique
*@param son
*@param k
*@param continuer 
*@return Nothing
*

*/

void exit_game(SDL_Surface *ecran,Mix_Music *musique,Mix_Chunk *button,int k,int *continuer,int s)
{
    int suit =1,a=0,i,z,ex[2],exprev=1,exprevb=1;
    SDL_Surface *bg=NULL,*option_exit[3];
    SDL_Rect position;

    position.x=0;
    position.y=0;

    bg=IMG_Load("19.png");
  option_exit[1]= IMG_Load("18.png");
option_exit[2]= IMG_Load("20.png");

   jouer_son(musique,k);
        SDL_BlitSurface(bg,NULL,ecran,&position);
    
    SDL_Flip(ecran);

    SDL_Event touch;

    while(suit)
    {   exprev=ex[0];
            exprevb=ex[1];
            arduinoReadDataEx(ex);


            if(ex[0]==0 && exprev!=0)
            {

                a--;
            }
            if(ex[0]==2 && exprev!=2)
            {
                a++;
            }

            if(ex[1]==1 && exprevb!=1)
            {
                if(a==1)
                {
                    *continuer=0;
                    suit=0;
                }
                else
                {
                    suit=0;
                }
            }
                 if(a>2)
            a=1;
        else if(a<1)
            a=2;
        
            SDL_WaitEvent(&touch);

        switch(touch.type)
        {
        case SDL_MOUSEMOTION:
            if(touch.motion.x>506 &&touch.motion.x<571&&touch.motion.y>381&&touch.motion.y<408)
            {if (s==1)
              Mix_PlayChannel(-1,button,0);
                a=1;

            }
            else if(touch.motion.x>686&&touch.motion.x<733&&touch.motion.y>379&&touch.motion.y<405)
            {if (s==1)
              Mix_PlayChannel(-1,button,0);
                a=2;

            }
            else a=0;
            break;
        case SDL_MOUSEBUTTONDOWN:
            if (touch.button.button==SDL_BUTTON_LEFT)
            {
                if(touch.motion.x>506 &&touch.motion.x<571&&touch.motion.y>381&&touch.motion.y<408)
                {
                    *continuer=0;
                    suit=0;
                }
                else if(touch.motion.x>686&&touch.motion.x<733&&touch.motion.y>379&&touch.motion.y<405)
                    {suit=0;
                     break;}
            }
            break;

        case SDL_KEYDOWN:
            switch(touch.key.keysym.sym)
            {
            case SDLK_LEFT:
               if (s==1)
              Mix_PlayChannel(-1,button,0);
                a--;
                break;

            case SDLK_RIGHT:
                if (s==1)
              Mix_PlayChannel(-1,button,0);
                a++;
                break;

            case SDLK_RETURN:
                if(a==1)
                {
                    *continuer=0;
                    suit=0;
                }
                else
                {
                    suit=0;
                }
                break;
            }
         if(a>2)
            a=1;
        else if(a<1)
            a=2;

            break;
        }
       
        /*if(a>2)
            a=1;
        else if(a<1)
            a=2;*/


        if(a>0&&a<3)
        {
            SDL_BlitSurface(option_exit[a],NULL,ecran,&position);
        }
        else if (a==0)

        SDL_BlitSurface(bg,NULL,ecran,&position);
        SDL_Flip(ecran);

    }
        SDL_FreeSurface(option_exit[1]);
        SDL_FreeSurface(option_exit[2]);
        SDL_FreeSurface(bg);
    

}




/*void buttons(SDL_Surface *ecran,Mix_Music *musique,Mix_Chunk *son,int k,int s)
{
    int i,continuer=1;

    SDL_Surface *buttons[10]= {NULL},*back=NULL;
    SDL_Rect position_back,position_button[10];
    
    position_back.x=0;
    position_back.y=470;

}*/


/**
*@brief changer input player1.
*@param ecran  
*@param k
*@param x choix du mouvement
*@param y choix du mouvement 
*@return Nothing
*

*/

void change1(SDL_Surface *ecran,int k,int* x, int* y,int s,Mix_Music *musique,Mix_Chunk *button)
{
SDL_Surface *change[6]= {NULL},*back=NULL;
SDL_Rect position_back,position[6];
    jouer_son(musique,k);
    position_back.x=0;
    position_back.y=470;
    position[0].x=0;
    position[0].y=0;
    position[1].x=430;
    position[1].y=298;
    position[2].x=430;
    position[2].y=412;
    position[3].x=640;
    position[3].y=289;
    position[4].x=694;
    position[4].y=346;
    position[5].x=716;
    position[5].y=483;


    change[0]=IMG_Load("option/bgcomplet.png");//bg
    //input[1]=IMG_Load("option/5.png");//5
    change[1]=IMG_Load("option/arrowb.png");//arrows
    change[2]=IMG_Load("option/13b.png");//13
    
    change[3]=IMG_Load("option/upb.png");//up
    change[4]=IMG_Load("option/spaceb.png");//space
    change[5]=IMG_Load("option/enterb.png");//enter
    
    back=IMG_Load("option/ban/arrow.png");
SDL_BlitSurface(change[0],NULL,ecran,&position[0]);
SDL_BlitSurface(back,NULL,ecran,&position_back);
     SDL_Flip(ecran);
    int suit=1,i;
    SDL_Event touch;
   while(suit)
    {
            SDL_WaitEvent(&touch);
            switch(touch.type)
            {
            case SDL_QUIT:
                suit=0;
                break;
    
            case SDL_MOUSEBUTTONDOWN:
                if (touch.button.button==SDL_BUTTON_LEFT)
                {
                    if(touch.button.x>452 && touch.button.x<608 && touch.button.y>312 && touch.button.y<369)
                        
                       (*x)=1;
                    else if(touch.button.x>455 && touch.button.x<606 && touch.button.y>414 && touch.button.y<470)
                    (*x)=2;
                    else if(touch.button.x>665 && touch.button.x<848 && touch.button.y>300 && touch.button.y<342)
                    (*y)=1;
                    else if(touch.button.x>717 && touch.button.x<789 && touch.button.y>376 && touch.button.y<464)
                     (*y)=2;
                    else if(touch.button.x>726 && touch.button.x<776 && touch.button.y>500 && touch.button.y<548)
                      (*y)=3;
                    else if(touch.button.x>40 && touch.button.x<220 && touch.button.y>530 && touch.button.y<655)//back
                    {
                       suit=0;
                    }
                   
                    }
                    break;

                
            }
        




SDL_BlitSurface(change[0],NULL,ecran,&position[0]);
if (*x==1)
      SDL_BlitSurface(change[1],NULL,ecran,&position[1]);
      else if (*x==2)
        SDL_BlitSurface(change[2],NULL,ecran,&position[2]); 
      if (*y==1)
      SDL_BlitSurface(change[4],NULL,ecran,&position[3]);
      else if (*y==2)
        SDL_BlitSurface(change[5],NULL,ecran,&position[4]);
       else if (*y==3)
        SDL_BlitSurface(change[3],NULL,ecran,&position[5]);
      SDL_BlitSurface(back,NULL,ecran,&position_back);
     SDL_Flip(ecran);

    }
    for(i=0;i<6;i++)
    {
        SDL_FreeSurface(change[i]);
    }
      SDL_FreeSurface(back);


}

/**
*@brief affichage input.
*@param ecran  
*@param k
*@param x choix du mouvement1
*@param y choix du mouvement 1
*@param x1 choix du mouvement2
*@param y1 choix du mouvement 2
*@return Nothing
*

*/

void input(int* x,int* y,int* x1,int* y1,SDL_Surface *ecran,int k,int s,Mix_Music *musique,Mix_Chunk *button)
{//initialiser t1 et t2 fel main
SDL_Surface *input[14]= {NULL},*back=NULL;
   jouer_son(musique,k);
    SDL_Rect position_back,position_input[9];
    
    position_back.x=0;
    position_back.y=470;

    position_input[0].x=0;
    position_input[0].y=0;
    position_input[1].x=454;
    position_input[1].y=202;
    position_input[2].x=725;
    position_input[2].y=202;
    position_input[3].x=729;
    position_input[3].y=525;
    position_input[4].x=464;
    position_input[4].y=525;

    position_input[5].x=444;
    position_input[5].y=320;
    position_input[6].x=486;
    position_input[6].y=415;

    position_input[7].x=705;
    position_input[7].y=320;
    position_input[8].x=751;
    position_input[8].y=415;


    input[0]=IMG_Load("option/bgchange.png");//bg
    input[1]=IMG_Load("option/1p.png");//p1
    input[2]=IMG_Load("option/2p.svg");//p2
    input[3]=IMG_Load("option/ar.png");//arrow

    input[4]=IMG_Load("option/arrow.png");//arrows
    input[5]=IMG_Load("option/13.png");//13
    input[6]=IMG_Load("option/qd.png");//qd
    input[7]=IMG_Load("option/wc.png");//wc
    input[8]=IMG_Load("option/up.png");//up
    input[9]=IMG_Load("option/5.png");//5
    input[10]=IMG_Load("option/enter.png");//enter
    input[11]=IMG_Load("option/z.png");//z
    input[12]=IMG_Load("option/shift.png");//shift
    input[13]=IMG_Load("option/space.png");//space
    back=IMG_Load("option/ban/arrow.png");

 int suit=1,i,b=0;
    for(i=0; i<3; i++)
    {   
        SDL_BlitSurface(input[i],NULL,ecran,&position_input[i]);
 
    }  
      if (*x==1)
      SDL_BlitSurface(input[4],NULL,ecran,&position_input[5]);
      else if (*x==2)
        SDL_BlitSurface(input[5],NULL,ecran,&position_input[5]); 
      if (*y==1)
      SDL_BlitSurface(input[8],NULL,ecran,&position_input[6]);
      else if (*y==2)
        SDL_BlitSurface(input[13],NULL,ecran,&position_input[6]);//mba3ed nrajaa ne9leb space and 5
       else if (*y==3)
        SDL_BlitSurface(input[10],NULL,ecran,&position_input[6]);
      
      if (*x1==1)
      SDL_BlitSurface(input[6],NULL,ecran,&position_input[7]);
      else if (*x1==2)
        SDL_BlitSurface(input[7],NULL,ecran,&position_input[7]); 
      if (*y1==1)
      SDL_BlitSurface(input[11],NULL,ecran,&position_input[8]);
      else if (*y1==2)
        SDL_BlitSurface(input[12],NULL,ecran,&position_input[8]);
       else if (*y1==3)
        SDL_BlitSurface(input[9],NULL,ecran,&position_input[8]); 
         
 SDL_BlitSurface(back,NULL,ecran,&position_back);
    SDL_Flip(ecran);

    SDL_Event touch;

    while(suit)
    {
            SDL_WaitEvent(&touch);
            switch(touch.type)
            {
            case SDL_QUIT:
                suit=0;
                break;
    
            case SDL_MOUSEMOTION:
                if(touch.motion.x>491 && touch.motion.x<571 && touch.motion.y>490 && touch.motion.y<526)
                    {if (s==1)
              Mix_PlayChannel(-1,button,0);SDL_BlitSurface(input[3],NULL,ecran,&position_input[4]);SDL_Delay(20);SDL_Flip(ecran);}
                else if(touch.motion.x>758 && touch.motion.x<838 && touch.motion.y>491 && touch.motion.y<529)
                    {if (s==1)
              Mix_PlayChannel(-1,button,0);SDL_BlitSurface(input[3],NULL,ecran,&position_input[3]);SDL_Delay(20);SDL_Flip(ecran);}
                else SDL_Flip(ecran);
                break;
            case SDL_MOUSEBUTTONDOWN:
                if (touch.button.button==SDL_BUTTON_LEFT)
                {
                    if(touch.button.x>491 && touch.button.x<571 && touch.button.y>490 && touch.button.y<526)//change1
                        { change1(ecran,k,x,y,s,musique,button);
                        }

                    else if(touch.button.x>758 && touch.button.x<838 && touch.button.y>491 && touch.button.y<529)//change2
                    { 
                        //change2(ecran,k,x1,y1);

                    }
                    
                    else if(touch.button.x>40 && touch.button.x<220 && touch.button.y>530 && touch.button.y<655)//back
                    {
                       suit=0;
                    }
                   
                    }
                    break;

                
            }
        






 for(i=0;i<3;i++)
    {   
        SDL_BlitSurface(input[i],NULL,ecran,&position_input[i]);
 
    }
 
         if (*x==1)
      SDL_BlitSurface(input[4],NULL,ecran,&position_input[5]);
      else if (*x==2)
        SDL_BlitSurface(input[5],NULL,ecran,&position_input[5]); 
      if (*y==1)
      SDL_BlitSurface(input[13],NULL,ecran,&position_input[6]);
      else if (*y==2)
        SDL_BlitSurface(input[10],NULL,ecran,&position_input[6]);
       else if (*y==3)
        SDL_BlitSurface(input[8],NULL,ecran,&position_input[6]);
      
      if (*x1==1)
      SDL_BlitSurface(input[6],NULL,ecran,&position_input[7]);
      else if (*x1==2)
        SDL_BlitSurface(input[7],NULL,ecran,&position_input[7]); 
      if (*y1==1)
      SDL_BlitSurface(input[11],NULL,ecran,&position_input[8]);
      else if (*y1==2)
        SDL_BlitSurface(input[12],NULL,ecran,&position_input[8]);
       else if (*y1==3)
        SDL_BlitSurface(input[9],NULL,ecran,&position_input[8]);
 SDL_BlitSurface(back,NULL,ecran,&position_back);

SDL_Flip(ecran);
    }
    for(i=0;i<14;i++)
    {
        SDL_FreeSurface(input[i]);
    }
      SDL_FreeSurface(back);
     

}






/**
*@brief affichage settings.
*@param ecran  
*@param musique
*@param son
*@param k
*@param x choix du mouvement1
*@param y choix du mouvement 1
*@param x1 choix du mouvement2
*@param y1 choix du mouvement 2
*@return Nothing
*

*/





void setting(SDL_Surface *ecran,Mix_Music *musique,Mix_Chunk *button,int *k,int *s,int* x,int* y,int* x1,int* y1)
{
    int i,a,suit=1,b=0,pos[2]= {0},u=1,z=0;


    SDL_Surface *option_setting[12]= {NULL},*back=NULL;
    SDL_Rect position_back,position_setting[12];
    
    position_back.x=0;
    position_back.y=470;

    position_setting[0].x=0;
    position_setting[0].y=0;
    position_setting[1].x=365;
    position_setting[1].y=106;
    position_setting[2].x=595;
    position_setting[2].y=182;
    position_setting[3].x=274;
    position_setting[3].y=70;
    position_setting[4].x=479;
    position_setting[4].y=127;
    position_setting[5].x=274;
    position_setting[5].y=70;
    position_setting[6].x=479;
    position_setting[6].y=127;
    position_setting[9].x=441;
    position_setting[9].y=395;
    position_setting[10].x=636;
    position_setting[10].y=430;
    position_setting[11].x=625;
    position_setting[11].y=420;
   

    option_setting[0]=IMG_Load("option/bg8.png");
    option_setting[1]=IMG_Load("option/voice.png");
    option_setting[2]=IMG_Load("option/music.png");
    option_setting[3]=IMG_Load("option/micro.png");
    option_setting[4]=IMG_Load("option/note.png");
    option_setting[5]=IMG_Load("option/nmicro.png");
    option_setting[6]=IMG_Load("option/nnote.png");
    option_setting[7]=IMG_Load("option/voicean.png");
    option_setting[8]=IMG_Load("option/musican.png");
    option_setting[9]=IMG_Load("option/fulls.png");
    option_setting[10]=IMG_Load("option/cl.png");
    option_setting[11]=IMG_Load("option/clan.png");



    back=IMG_Load("option/ban/arrow.png");

    jouer_son(musique,*k);

    suit=1;
    for(i=0; i<3; i++)
    { 
        SDL_BlitSurface(option_setting[i],NULL,ecran,&position_setting[i]);
 
    }
    SDL_BlitSurface(option_setting[9],NULL,ecran,&position_setting[9]);
    SDL_BlitSurface(option_setting[10],NULL,ecran,&position_setting[10]);
if (*k!=0)
SDL_BlitSurface(option_setting[4],NULL,ecran,&position_setting[4]);
  else 
SDL_BlitSurface(option_setting[6],NULL,ecran,&position_setting[6]);
if (*s!=0)
SDL_BlitSurface(option_setting[3],NULL,ecran,&position_setting[3]);
  else
SDL_BlitSurface(option_setting[5],NULL,ecran,&position_setting[5]);
SDL_BlitSurface(back,NULL,ecran,&position_back);
    SDL_Flip(ecran);

    SDL_Event touch;

    while(suit)
    {
            SDL_WaitEvent(&touch);
            switch(touch.type)
            {
            case SDL_QUIT:
                suit=0;
                break;
              case SDL_KEYDOWN:
                switch(touch.key.keysym.sym)
                {
                case SDLK_UP:
                    if (*s==1)
              Mix_PlayChannel(-1,button,0);
                    b--;
                    break;
                case SDLK_DOWN:
                        if (*s==1)
              Mix_PlayChannel(-1,button,0);
                    b++;
                    break;
                case SDLK_RETURN:
                    if(b==1)
                        {if ((*s)!=0)
                      {SDL_BlitSurface(option_setting[5],NULL,ecran,&position_setting[5]);(*s)=0;}
                       else
                       {SDL_BlitSurface(option_setting[3],NULL,ecran,&position_setting[3]);(*s)=1;}
                         
                             SDL_Flip(ecran); }
                    else if(b==2)
                    { 

                        if ((*k)==0)
                       {SDL_BlitSurface(option_setting[4],NULL,ecran,&position_setting[4]);(*k)=1;}
                      
                       else
                       {SDL_BlitSurface(option_setting[6],NULL,ecran,&position_setting[6]);(*k)=0;}
                         
                             SDL_Flip(ecran); 


                    }

                    else if(b==3)
                    {
                       input(x,y,x1,y1,ecran,*k,*s,musique,button);
                       
                    }

                }
                if (b>3)
            b=1;
        if(b<1)
            b=3;
                break;
            case SDL_MOUSEMOTION:
                if(touch.motion.x>514 && touch.motion.x<628 && touch.motion.y>255 && touch.motion.y<304)
                    {if (*s==1)
              Mix_PlayChannel(-1,button,0);b=1;}
                else if(touch.motion.x>746 && touch.motion.x<873 && touch.motion.y>331 && touch.motion.y<385)
                    {if (*s==1)
              Mix_PlayChannel(-1,button,0);b=2;}
                else if(touch.motion.x>634 && touch.motion.x<857 && touch.motion.y>452 && touch.motion.y<513)
                    {if (*s==1)
              Mix_PlayChannel(-1,button,0);b=3;}
                else b=0;
                break;
            case SDL_MOUSEBUTTONDOWN:
                if (touch.button.button==SDL_BUTTON_LEFT)
                {
                    if(touch.button.x>514 && touch.button.x<628 && touch.button.y>255 && touch.button.y<304)
                        {if ((*s)!=0)
                      {SDL_BlitSurface(option_setting[5],NULL,ecran,&position_setting[5]);(*s)=0;}
                       else
                       {SDL_BlitSurface(option_setting[3],NULL,ecran,&position_setting[3]);(*s)=1;}
                         
                             SDL_Flip(ecran); }

                    if(touch.button.x>746 && touch.button.x<873 && touch.button.y>331 && touch.button.y<385)
                    { 

                        if ((*k)==0)
                       {SDL_BlitSurface(option_setting[4],NULL,ecran,&position_setting[4]);(*k)=1;}
                      
                       else
                       {SDL_BlitSurface(option_setting[6],NULL,ecran,&position_setting[6]);(*k)=0;}
                         
                             SDL_Flip(ecran); 


                    }
                    else if(touch.button.x>455 && touch.button.x<584 && touch.button.y>408 && touch.button.y<534)
                    {
                        //b=3;
                        ecran =SDL_GetVideoSurface();
                        Uint32 flags=(ecran->flags^SDL_FULLSCREEN);
                        ecran =SDL_SetVideoMode(0,0,0, flags);
                    }
                    else if(touch.button.x>634 && touch.button.x<857 && touch.button.y>452 && touch.button.y<513)
                    {
                        input(x,y,x1,y1,ecran,*k,*s,musique,button);
                    }
                    else if(touch.button.x>40 && touch.button.x<220 && touch.button.y>530 && touch.button.y<655)
                    {
                       suit=0;
                    }
                   
                    }
                    break;

                
            }
        

       /* if (b>4)
            b=1;
        if(b<1)
            b=4;

        if((*k)>10)
            (*k)=10;
        else if((*k)<1)
            (*k)=1;*/

       // Mix_VolumeChunk(son, MIX_MAX_VOLUME/(10/(*k)));
       // Mix_VolumeMusic(MIX_MAX_VOLUME /(10/(*k)));
    
      jouer_son(musique,*k);
     
        SDL_BlitSurface(option_setting[0],NULL,ecran,&position_setting[0]);
 
    
if ((*k)!=0)
SDL_BlitSurface(option_setting[4],NULL,ecran,&position_setting[4]);
  else 
SDL_BlitSurface(option_setting[6],NULL,ecran,&position_setting[6]);
if ((*s)!=0)
SDL_BlitSurface(option_setting[3],NULL,ecran,&position_setting[3]);
  else
SDL_BlitSurface(option_setting[5],NULL,ecran,&position_setting[5]);
SDL_BlitSurface(back,NULL,ecran,&position_back);
SDL_BlitSurface(option_setting[9],NULL,ecran,&position_setting[9]);
SDL_BlitSurface(option_setting[10],NULL,ecran,&position_setting[10]);       
        SDL_Flip(ecran);
if (b==1)
   {SDL_BlitSurface(option_setting[7],NULL,ecran,&position_setting[1]);
   SDL_BlitSurface(option_setting[2],NULL,ecran,&position_setting[2]);SDL_Flip(ecran);}
else if (b==2)
    {SDL_BlitSurface(option_setting[8],NULL,ecran,&position_setting[2]);
    SDL_BlitSurface(option_setting[1],NULL,ecran,&position_setting[1]);SDL_Flip(ecran);}
else 
   { SDL_BlitSurface(option_setting[2],NULL,ecran,&position_setting[2]);
    SDL_BlitSurface(option_setting[1],NULL,ecran,&position_setting[1]);SDL_Flip(ecran);}
if (b==3)
SDL_BlitSurface(option_setting[11],NULL,ecran,&position_setting[11]);
SDL_Flip(ecran);
    }
    for (int i = 0; i < 11; i++)
    {
        SDL_FreeSurface(option_setting[i]);
    }
      SDL_FreeSurface(back);
}




/**
*@brief choix des personnage.
*@param ecran  
*@param musique
*@param son
*@param k 
*@param x choix du mouvement1
*@param y choix du mouvement 1
*@param x1 choix du mouvement2
*@param y1 choix du mouvement 2
*@return Nothing
*

*/


void onep(SDL_Surface* screen,Mix_Music *musique,Mix_Chunk *button,int k,int x,int y,char* nomfich,int s)
{

jouer_son(musique,k);
    SDL_Surface *player[5]= {NULL},*back=NULL;
    SDL_Rect position_back,position;
    
    position_back.x=0;
    position_back.y=470;

    position.x=0;
    position.y=0;
    player[0]=IMG_Load("2.png");
    player[1]=IMG_Load("3.png");
    player[2]=IMG_Load("4.png");
    player[3]=IMG_Load("5.png");
    player[4]=IMG_Load("6.png");
    back=IMG_Load("option/ban/arrow.png");
    jouer_son(musique,k);
SDL_BlitSurface(player[0],NULL,screen,&position);
SDL_BlitSurface(back,NULL,screen,&position_back);
SDL_Flip(screen);
int continuer=1,b=0,i,choix=0;

 SDL_Event touch;

    while(continuer)
    {     //SDL_BlitSurface(player[b],NULL,screen,&position);
          //SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,0,0,0));
            SDL_WaitEvent(&touch);
            switch(touch.type)
            {
            case SDL_QUIT:
                continuer=0;
                break;
            case SDL_MOUSEMOTION:
                if(touch.motion.x>517 && touch.motion.x<621 && touch.motion.y>257 && touch.motion.y<358)
                   {if (s==1)
              Mix_PlayChannel(-1,button,0); b=1;}//nadhir
                else if(touch.motion.x>670 && touch.motion.x<772 && touch.motion.y>257 && touch.motion.y<357)
                    {if (s==1)
              Mix_PlayChannel(-1,button,0);b=2;}//wassim
                else if(touch.motion.x>518 && touch.motion.x<621 && touch.motion.y>401 && touch.motion.y<500)
                   {if (s==1)
              Mix_PlayChannel(-1,button,0); b=3;}//hichri
                else if(touch.motion.x>669 && touch.motion.x<772 && touch.motion.y>402 && touch.motion.y<500)
                    {if (s==1)
              Mix_PlayChannel(-1,button,0);b=4; }//malek
                else b=0;
                break;


                case SDL_KEYDOWN:
            switch(touch.key.keysym.sym)
            {
            case SDLK_LEFT:
                if (s==1)
              Mix_PlayChannel(-1,button,0);
                b--;
                break;

            case SDLK_RIGHT:
                if (s==1)
              Mix_PlayChannel(-1,button,0);
                b++;
                break;

            case SDLK_RETURN:
                if(b==1)
                {
                    choix=1;stage1(screen,k,choix,x,y,nomfich,musique);//stage1 est developpee dans play.c
continuer=0;
                }
                else if (b==2)
                {
                    choix=2;//SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,0,0,0));
stage1(screen,k,choix,x,y,nomfich,musique);
continuer=0;
                }
                else if (b==3)
                {
                    choix=3;//SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,0,0,0));
stage1(screen,k,choix,x,y,nomfich,musique);
continuer=0;
                }
                else if (b==4)
                {
                    choix=4;//SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,0,0,0));
stage1(screen,k,choix,x,y,nomfich,musique);
continuer=0;
                }
                break;
            }
         if(b>4)
            b=1;
        else if(b<1)
            b=4;

            break;

            case SDL_MOUSEBUTTONDOWN:
                if (touch.button.button==SDL_BUTTON_LEFT)
                {
                    if(touch.button.x>517 && touch.button.x<621 && touch.button.y>257 && touch.button.y<358)
                        {choix=1;stage1(screen,k,choix,x,y,nomfich,musique);//stage1 est developpee dans play.c
continuer=0;
                            }

                    else if(touch.button.x>670 && touch.button.x<772 && touch.button.y>257 && touch.button.y<357)
                    {jouer_son(musique,k);

                        choix=2;//SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,0,0,0));
stage1(screen,k,choix,x,y,nomfich,musique);
continuer=0;
                    }
                    else if(touch.button.x>518 && touch.button.x<621 && touch.button.y>401 && touch.button.y<500)
                    {jouer_son(musique,k);
                     choix=3;//SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,0,0,0));
stage1(screen,k,choix,x,y,nomfich,musique);
continuer=0;
                        
                    }
                    else if(touch.button.x>669 && touch.button.x<772 && touch.button.y>402 && touch.button.y<500)
                    {jouer_son(musique,k);

                         choix=4;//SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,0,0,0));
stage1(screen,k,choix,x,y,nomfich,musique);
continuer=0;
                    }
                    else if(touch.button.x>40 && touch.button.x<220 && touch.button.y>530 && touch.button.y<655)
                    {
                       continuer=0;
                    }
                   
                    }
                    break;

                
            }
         
        SDL_BlitSurface(player[b],NULL,screen,&position);

SDL_BlitSurface(back,NULL,screen,&position_back);
SDL_Flip(screen);
}
 SDL_FreeSurface(back);
   for (i=0;i<5;i++)
 SDL_FreeSurface(player[i]);
//SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,0,0,0));
/*if (choix!=0)
stage1(screen,k,choix,x,y);*/

}



/**
*@brief choix du nombre des joeurs.
*@param ecran  
*@param musique
*@param son
*@param k 
*@param x choix du mouvement1
*@param y choix du mouvement 1
*@param x1 choix du mouvement2
*@param y1 choix du mouvement 2
*@param nomfich nomfichier du sauvegarde
*@return Nothing
*

*/


void newgame (SDL_Surface* screen,Mix_Music *musique,Mix_Chunk *button,int k,int x,int y,int x1,int y1,char* nomfich,int s)
{
SDL_Surface *joeur[4]= {NULL},*back=NULL;
    SDL_Rect position_back,position,positionbg;
    jouer_son(musique,k);
    position_back.x=0;
    position_back.y=470;

    positionbg.x=0;
    positionbg.y=0;
    position.x=282;
    position.y=(-14);
    joeur[0]=IMG_Load("13.png");
    joeur[1]=IMG_Load("j1.png");
    joeur[2]=IMG_Load("j11.png");
    joeur[3]=IMG_Load("j22.png");
    
    back=IMG_Load("option/ban/arrow.png");
    jouer_son(musique,k);
SDL_BlitSurface(joeur[0],NULL,screen,&positionbg);
SDL_BlitSurface(joeur[1],NULL,screen,&position);
SDL_BlitSurface(back,NULL,screen,&position_back);
SDL_Flip(screen);
int continuer=1,b=0, i;

 SDL_Event touch;

    while(continuer)
    {
            SDL_WaitEvent(&touch);
            switch(touch.type)
            {
            case SDL_QUIT:
                continuer=0;
                break;
            case SDL_MOUSEMOTION:
                if(touch.motion.x>610 && touch.motion.x<701 && touch.motion.y>270 && touch.motion.y<355)
                    {if (s==1)
              Mix_PlayChannel(-1,button,0);b=1;}
                else if(touch.motion.x>584 && touch.motion.x<730 && touch.motion.y>368 && touch.motion.y<450)
                   {if (s==1)
              Mix_PlayChannel(-1,button,0); b=2;}
                
                else b=0;
                break;
            case SDL_KEYDOWN:
            switch(touch.key.keysym.sym)
            {
            case SDLK_UP:
                if (s==1)
              Mix_PlayChannel(-1,button,0);
                b--;
                break;

            case SDLK_DOWN:
                if (s==1)
              Mix_PlayChannel(-1,button,0);
                b++;
                break;

            case SDLK_RETURN:
                if(b==1)
                {
                    onep(screen,musique,button,k,x,y,nomfich,s);
                }
                else if (b==2)
                {
                    jouer_son(musique,k);
                }
                break;
            }
         if(b>2)
            b=1;
        else if(b<1)
            b=2;

            break;
            case SDL_MOUSEBUTTONDOWN:
                if (touch.button.button==SDL_BUTTON_LEFT)
                {
                    if(touch.button.x>610 && touch.button.x<701 && touch.button.y>270 && touch.button.y<355)
                        {   onep(screen,musique,button,k,x,y,nomfich,s);
                            jouer_son(musique,k);}

                    else if(touch.button.x>584 && touch.button.x<730 && touch.button.y>368 && touch.button.y<450)
                    {jouer_son(musique,k);

                        
                    }
                    
                    else if(touch.button.x>40 && touch.button.x<220 && touch.button.y>530 && touch.button.y<655)
                    {
                       continuer=0;
                    }
                   
                    }
                    break;

                
            }
        SDL_BlitSurface(joeur[0],NULL,screen,&positionbg);
        
         if (b==1)
        {SDL_BlitSurface(joeur[2],NULL,screen,&position);SDL_Flip(screen);}
         else if (b==2)
         {SDL_BlitSurface(joeur[3],NULL,screen,&position);SDL_Flip(screen);}
          else  {SDL_BlitSurface(joeur[1],NULL,screen,&position);SDL_Flip(screen);}
SDL_BlitSurface(back,NULL,screen,&position_back);
SDL_Flip(screen);
}
 SDL_FreeSurface(back);
   for (i=0;i<4;i++)
 SDL_FreeSurface(joeur[i]);





}



/**
*@brief initialisation de l'ancienne partie.
*@param ecran  
*@param musique
*@param son
*@param nomfich nom fichier du sauvegarde
*@return Nothing
*

*/



void loadgame(SDL_Surface* screen,Mix_Music *musique,Mix_Chunk *button,char* nomfich,player* p,int* posx,int* posy,int* choix,int* s)
{FILE *f=NULL;
SDL_Rect position ,pos;
int stage,vie,x,y;
int px,py,dir;
char direction ;
//player tmp;
temps t;
    f=fopen(nomfich,"r");
    if (!feof(f))
     {fscanf(f,"%d %d %d %d %d %d %d %d %d %d %d\n",&px,&py,choix,&stage,&vie,&dir,&x,&y,posx,posy,s);
    
    fclose(f);}
//printf ("posx %d posy %d choix pers%d  stage%d vie%d %d %d %d %d %d\n",px,py,choix,p.stage,p.vie,dir,p.x,p.y,posx,posy);
if (dir==1)
p->direction='r';
else if (dir==2)
p->direction='l';
p->position.x=px;
p->position.y=py;
p->x=x;p->y=y;p->vie=vie;p->stage=stage;



}


/**
*@brief load or new game.
*@param ecran  
*@param musique
*@param son
*@param k 
*@param x choix du mouvement1
*@param y choix du mouvement 1
*@param x1 choix du mouvement2
*@param y1 choix du mouvement 2
*@param nomfich nomfichier du sauvegarde
*@return Nothing
*

*/


void play (SDL_Surface* screen,Mix_Music *musique,Mix_Chunk *button,int k,int x,int y,int x1,int y1,char* nomfich,int s)
{
int posx,posy,choix,sc=0;
SDL_Surface* bg,*back,*an1,*an2;
player p;
SDL_Rect position,position_back;
bg=IMG_Load("15.png");
an1=IMG_Load("16.png");
an2=IMG_Load("17.png");
back=IMG_Load("option/ban/arrow.png");
 position_back.x=0;
    position_back.y=470;
 position.x=0;
    position.y=0;
jouer_son(musique,k);
SDL_BlitSurface(bg,NULL,screen,&position);
SDL_BlitSurface(back,NULL,screen,&position_back);
SDL_Flip(screen);
int continuer=1,b=0;

 SDL_Event touch;

    while(continuer)
    {
            SDL_WaitEvent(&touch);
            switch(touch.type)
            {
            case SDL_QUIT:
                continuer=0;
                break;
           case SDL_KEYDOWN:
            switch(touch.key.keysym.sym)
            {
            case SDLK_UP:
              if (s==1)
              Mix_PlayChannel(-1,button,0);
                b--;
                break;

            case SDLK_DOWN:
            if (s==1)
              Mix_PlayChannel(-1,button,0);
                b++;
                break;

            case SDLK_RETURN:
                if(b==1)
                {if (s==1)
              Mix_PlayChannel(-1,button,0);
                   newgame(screen,musique,button,k,x,y,x1,y1,nomfich,s); 
                }
                else if (b==2)
                {if (s==1)
              Mix_PlayChannel(-1,button,0);
                    loadgame(screen,musique,button,nomfich,&p,&posx,&posy,&choix,&sc);
                      loadstage1(screen,p,nomfich,choix,posx,posy,sc,s,musique);  continuer=0;
                }
                break;
            }
         if(b>2)
            b=1;
        else if(b<1)
            b=2;

            break;
        
                 
            case SDL_MOUSEMOTION:
                if(touch.motion.x>484 && touch.motion.x<800 && touch.motion.y>248 && touch.motion.y<300)
                    b=1;
                else if(touch.motion.x>487 && touch.motion.x<805 && touch.motion.y>345 && touch.motion.y<395)
                    b=2;
                else b=0;
                break;
            case SDL_MOUSEBUTTONDOWN:
                if (touch.button.button==SDL_BUTTON_LEFT)
                {
                    if(touch.button.x>484 && touch.button.x<800 && touch.button.y>248 && touch.button.y<300)
                        {newgame(screen,musique,button,k,x,y,x1,y1,nomfich,s);
jouer_son(musique,k);}

                    else if(touch.button.x>487 && touch.button.x<805 && touch.button.y>345 && touch.button.y<395)
                    {jouer_son(musique,k);

                        loadgame(screen,musique,button,nomfich,&p,&posx,&posy,&choix,&sc);
                      loadstage1(screen,p,nomfich,choix,posx,posy,sc,s,musique);           
                      continuer=0;
                    }
                    else if(touch.button.x>40 && touch.button.x<220 && touch.button.y>530 && touch.button.y<655)
                    {
                       continuer=0;
                    }
                   
                    }
                    break;

                
            }
         if (b==1)
        SDL_BlitSurface(an1,NULL,screen,&position);
         else if (b==2)
         SDL_BlitSurface(an2,NULL,screen,&position);
else  SDL_BlitSurface(bg,NULL,screen,&position);
SDL_BlitSurface(back,NULL,screen,&position_back);
SDL_Flip(screen);
}
 SDL_FreeSurface(back);
 SDL_FreeSurface(bg);
 SDL_FreeSurface(an1);
 SDL_FreeSurface(an2);

}













/*



void multip (SDL_Surface* screen,Mix_Music *musique,Mix_Chunk *son,int k)
{





}

*/


