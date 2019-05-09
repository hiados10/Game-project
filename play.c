#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <string.h>
#include "play.h"
#include "menu.h"

//#include "enigme.c"
//#include "EnigmaF.c"

//char nomfich[]="save.txt";


/**
*@brief changer position du bg.
*@param ecran  l'ecran
*@param stage image du stage
*@param h structure du joeur
*@param posbg position du bg
*@param direction direction actuelle du joeur.
*@return scroll 
*

*/


int scrolling(SDL_Surface * ecran,SDL_Surface * stage,player *h,SDL_Rect *posbg,char direction)
{

    int scroll=0;
    switch(direction)
    {
        case 'r' :
        if(h->position.x>ecran->clip_rect.w/2)
        {
            scroll = 1;
            posbg->x=posbg->x+100;
        }
        break;
        case 'l':
        if(h->position.x < ecran->clip_rect.w/2 && posbg->x > 0)
        {
            scroll=-1;
            posbg->x=posbg->x-100;
        }

        break;
 }
    return scroll;
}


/**
*@brief recupere couleur du bg.
*@param fond_collision fond du collision
*@param position position du joeur
*@return couleur couleur recuperee
*

*/



SDL_Color recuperer_couleur(SDL_Surface *fond_collision,SDL_Rect position)
{
    SDL_Color couleur;
    Uint32 coul =0;

    char* Pposition = fond_collision->pixels;

    Pposition+=fond_collision->pitch *position.y;
    Pposition+=fond_collision->format->BytesPerPixel *position.x;
    memcpy(&coul,Pposition, fond_collision->format->BytesPerPixel);
    SDL_GetRGB(coul,fond_collision->format,&couleur.r,&couleur.g,&couleur.b);

    //printf("couleur recuperee\n");

    return couleur;
}

/**
*@brief verifie la collision.
*@param fond_collision 
*@param position_pers position du joeur
*@param position_camera position du camera
*@return 1 si collision 0 si pas de collision
*

*/


int verifier_collision(SDL_Surface *fond_collision,SDL_Rect position_pers,SDL_Rect position_camera)
{
   //SDL_Rect position_camera;
 //position_camera.x=0;
//position_camera.y=0;
    
    SDL_Color couleur_col,couleur_col2;
    SDL_Color couleur_recupere1;
    SDL_Color couleur_recupere2;
    SDL_Color couleur_recupere3;
    SDL_Color couleur_recupere4;

    SDL_Rect position1,position2,position3,position4,position;
    int largeur=101,hauteur=450,bord=100;

    position.x=position_camera.x+position_pers.x;
    position.y=position_camera.y+position_pers.y;

    position1.x=position.x+(largeur/2);
    position1.y=position.y+bord;

    position2.x=position.x+largeur-bord;
    position2.y=position.y+(hauteur/2);

    position3.x=position.x+(largeur/2);
    position3.y=position.y+hauteur-bord;

    position4.x=position.x+bord;
    position4.y=position.y+(hauteur/2);


    couleur_col.r=255;
    couleur_col.g=255;
    couleur_col.b=255;
    couleur_col2.r=255;
    couleur_col2.g=0;
    couleur_col2.b=0;

    couleur_recupere1=recuperer_couleur(fond_collision,position1);
    couleur_recupere2=recuperer_couleur(fond_collision,position2);
    couleur_recupere3=recuperer_couleur(fond_collision,position3);
    couleur_recupere4=recuperer_couleur(fond_collision,position4);


    if(couleur_col.r==couleur_recupere1.r&&couleur_col.g==couleur_recupere1.g&&couleur_col.b==couleur_recupere1.b)
    {
        printf("collision\n");
        return 1;
    }
    if(couleur_col.r==couleur_recupere2.r&&couleur_col.g==couleur_recupere2.g&&couleur_col.b==couleur_recupere2.b)
    { printf("collision\n");
        
        return 1;
    }
    if(couleur_col.r==couleur_recupere3.r&&couleur_col.g==couleur_recupere3.g&&couleur_col.b==couleur_recupere3.b)
    { printf("collision\n");
        return 1;
    }
    if(couleur_col.r==couleur_recupere4.r&&couleur_col.g==couleur_recupere4.g&&couleur_col.b==couleur_recupere4.b)
    { printf("collision\n");
        return 1;
    }
     /*if(couleur_col2.r==couleur_recupere1.r&&couleur_col2.g==couleur_recupere1.g&&couleur_col2.b==couleur_recupere1.b)
    {
        printf("collision\n");
        return 2;
    }
    if(couleur_col2.r==couleur_recupere2.r&&couleur_col2.g==couleur_recupere2.g&&couleur_col2.b==couleur_recupere2.b)
    { printf("collision\n");
        
        return 2;
    }
    if(couleur_col2.r==couleur_recupere3.r&&couleur_col2.g==couleur_recupere3.g&&couleur_col2.b==couleur_recupere3.b)
    { printf("collision\n");
        return 2;
    }
    if(couleur_col2.r==couleur_recupere4.r&&couleur_col2.g==couleur_recupere4.g&&couleur_col2.b==couleur_recupere4.b)
    { printf("collision\n");
        return 2;
    }*/
 //printf("pas de collision\n");
    return 0;
}

/**
*@brief permet de sauvegarder la partie.
*@param nom_fichier nom du fichier du sauvegarde.
*@param p le joeur
*@param t temps restant
*@param pos position du camera
*@param choix choix du perssonage
*@return Nothing
*

*/


void sauvegarder(char *nom_de_fichier,player p,SDL_Rect pos,int choix,int s)
{
    FILE *f=NULL;
    f=fopen(nom_de_fichier,"w");
int posx=pos.x,posy=pos.y,px=p.position.x,py=p.position.y,dir;
char pdir=p.direction;
if (p.direction=='r')
dir=1;
else
 dir=2;
    if (!feof(f))
   
        {fprintf(f,"%d %d %d %d %d %d %d %d %d %d %d\n",px,py,choix,p.stage,p.vie,dir,p.x,p.y,posx,posy,s);
    
    fclose(f);}
    

}
/**
*@brief initiliser temps.
*@param t temps restant
*@return Nothing
*

*/

void temps_jeu(temps *t)
{
    t->commencer=SDL_GetTicks();
}
/**
*@brief compter temps.
*@param t temps restant
*@return Nothing
*

*/
void compter_temps_stage1(temps *t)
{
    
        t->temps_stage1=SDL_GetTicks()-t->commencer;

}
/**
*@brief convertir les milliseconde.
*@param temps_milli temps a convertir
*@return temps
*

*/
int convertir_milliseconde(int temps_milli)
{
    return temps_milli/1000;
}

/**
*@brief affichage du temps.
*@param t temps restant
*@param ecran l'ecran
*@param stage numero du stage
*@return Nothing
*

*/

void afficher_temps(temps t,SDL_Surface* ecran,int stage)
{
    int seconde=0,minute=0,temps_stage2=60*2*1000,temps_stage3=60*3*1000,delta_temps;
    char temps[10];

    SDL_Surface *Temps=NULL;
    SDL_Rect position_temps;
    position_temps.x=0;
    position_temps.y=0;

    if(stage==1)
    {
        delta_temps=temps_stage2 - t.temps_stage1;
    }
   /* else if(stage==2)
    {
        delta_temps=temps_stage3 - t.temps_stage2;
    }*/

    seconde=convertir_milliseconde(delta_temps);
    while(seconde>59)
    {
        minute++;
        seconde-=60;
    }

    sprintf(temps,"%d:%d",minute,seconde);
    printf("%s\n",temps );

    TTF_Font *police=NULL;
    police=TTF_OpenFont("Police/Heroes Legend.ttf",30);

    SDL_Color couleur_score1= {255,0,0};
    SDL_Color couleur_score2= {0,255,0};
    if(delta_temps<30*1000)
    {
        Temps=TTF_RenderText_Solid(police,temps,couleur_score1);
    }
    else
    {
        Temps=TTF_RenderText_Solid(police,temps,couleur_score2);
    }

    SDL_BlitSurface(Temps,NULL,ecran,&position_temps);

    TTF_CloseFont(police);
    SDL_FreeSurface(Temps);

}



/**
*@brief initialiser personnage.
*@param choix choix du perssonage
*@param p le joeur
*@param x choix des touches
*@param y choix des touches2

*@return Nothing
*

*/


void initialiserp(int choix,player* p,int x,int y)
{int i;
p->position.x=750;
p->position.y=300;
p->stage=1;
p->vie=3;
p->enig1=0;
p->enig2=0;
p->enig3=0;
if (choix==1)
{printf("nadhir \n");
p->imager[0]=IMG_Load("Image/nadhir.png");
p->imager[1]=IMG_Load("Image/nadhir.png");
p->imager[2]=IMG_Load("Image/nadhir.png");
p->imager[3]=IMG_Load("Image/nadhir.png");
p->imagel[0]=IMG_Load("Image/nadhir.png");
p->imagel[1]=IMG_Load("Image/nadhir.png");
p->imagel[2]=IMG_Load("Image/nadhir.png");
p->imagel[3]=IMG_Load("Image/nadhir.png");
}
else if (choix==3)
{printf("hichri \n");
p->imager[0]=IMG_Load("Image/hichri.png");
p->imager[1]=IMG_Load("Image/hichri.png");
p->imager[2]=IMG_Load("Image/hichri.png");
p->imager[3]=IMG_Load("Image/hichri.png");
p->imagel[0]=IMG_Load("Image/hichri.png");
p->imagel[1]=IMG_Load("Image/hichri.png");
p->imagel[2]=IMG_Load("Image/hichri.png");
p->imagel[3]=IMG_Load("Image/hichri.png");
}
else if (choix==4)
{printf("malek \n");
p->imager[0]=IMG_Load("Image/malek.png");
p->imager[1]=IMG_Load("Image/malek.png");
p->imager[2]=IMG_Load("Image/malek.png");
p->imager[3]=IMG_Load("Image/hichri.png");
p->imagel[0]=IMG_Load("Image/hichri.png");
p->imagel[1]=IMG_Load("Image/hichri.png");
p->imagel[2]=IMG_Load("Image/hichri.png");
p->imagel[3]=IMG_Load("Image/hichri.png");
}
else if (choix==2)
{printf("wassim \n");
p->imager[0]=IMG_Load("was1.png");
p->imager[1]=IMG_Load("was2.png");
p->imager[2]=IMG_Load("was3.png");
p->imager[3]=IMG_Load("was4.png");
p->imagel[0]=IMG_Load("Wassim1.png");
p->imagel[1]=IMG_Load("Wassim2.png");
p->imagel[2]=IMG_Load("Wassim3.png");
p->imagel[3]=IMG_Load("Wassim4.png");
printf("ici\n");
}
p->direction='r';
p->x=x;
p->y=y;
printf("personnage initialisee \n");

}


/**
*@brief recuperer touches.
*@param tab tableau des mouvements
*@param press touche recuperee
*@param x choix des touches
*@param y choix des touches2

*@return Nothing
*

*/

void recuperer_touch(int tab[],SDL_Event press,int x,int y)
{
   int i;
    switch(press.type)
    {
    case SDL_KEYDOWN:
        if (x==1)
        {switch(press.key.keysym.sym)
        
        {case SDLK_LEFT:
            tab[0]=1;printf("l\n");
            break;

        case SDLK_RIGHT:
            tab[1]=1;printf("r\n");
            break;

        /*case SDLK_UP:
            tab[2]=1;
            break;

        case SDLK_DOWN:
            tab[3]=1;
            break;

        case SDLK_LSHIFT:
            tab[4]=1;
            break;
        case SDLK_ESCAPE:
            tab[5]=1;
            break;*/

        }}
   else if (x==2)
        {switch(press.key.keysym.sym)
        
        {case SDLK_1:
            tab[0]=1;
            break;

        case SDLK_3:
            tab[1]=1;
            break;

        }}
  
      if (y==3)//
         {switch(press.key.keysym.sym)
        
        {case SDLK_UP:
            tab[2]=1;printf("up\n");
            break;

        }}
        
       else  if (y==2)
         {switch(press.key.keysym.sym)
        
        {case SDLK_RETURN:
            tab[2]=1;
            break;

        }}
        else  if (y==1)
         {switch(press.key.keysym.sym)
        
        {case SDLK_SPACE: printf("space\n");
            tab[2]=1;
            break;

        }}
        

       break;

    case SDL_KEYUP:
         for (i=0;i<3;i++)
         tab[i]=0;
       /* if (x==1)
        {switch(press.key.keysym.sym)
        
        {case SDLK_LEFT:
            tab[0]=0;
            break;

        case SDLK_RIGHT:
            tab[1]=0;
            break;

        }}
   else if (x==2)
        {switch(press.key.keysym.sym)
        
        {case SDLK_1:
            tab[0]=0;
            break;

        case SDLK_3:
            tab[1]=0;
            break;

        }}
       
    if (y==3)//
         {switch(press.key.keysym.sym)
        
        {case SDLK_UP:
            tab[2]=0;
            break;

        }}
        
       else  if (y==2)
         {switch(press.key.keysym.sym)
        
        {case SDLK_RETURN:
            tab[2]=0;
            break;

        }}
        else  if (y==1)
         {switch(press.key.keysym.sym)
        
        {case SDLK_SPACE:
            tab[2]=0;
            break;

        }}*/
        

       break;

}
    
    
    printf("recuperee\n");
}

/**
*@brief annimation du personnage.
*@param ecran 
*@param p le joeur
*@param bg le background
*@param position position du personnage
*@param positions position de l'ecran
*@return Nothing
*

*/

void animation(SDL_Surface* ecran,player* p,SDL_Surface* bg,SDL_Rect position,SDL_Rect positions)
{


int i=0;

if (p->direction =='r')
for (i=0;i<4;i++)
{SDL_BlitSurface(bg, &position, ecran, &positions);
SDL_Flip(ecran);
SDL_BlitSurface(p->imager[i],NULL,ecran,&p->position);
SDL_Flip(ecran);SDL_Delay(100);}
else if (p->direction =='l')
for (i=0;i<4;i++)
{SDL_BlitSurface(bg, &position, ecran, &positions);
SDL_Flip(ecran);
SDL_BlitSurface(p->imagel[i],NULL,ecran,&p->position);
SDL_Flip(ecran);SDL_Delay(100);}

}


/**
*@brief sauvegarder ou non.
*@param ecran 
*@return 1 ou 2
*

*/

int pause(SDL_Surface* ecran)
{

SDL_Surface* pause[4];
SDL_Rect pos[4];
int suit=1,i;
pos[0].x=150;
pos[0].y=0;
pos[1].x=150;
pos[1].y=0;
pos[2].x=150;
pos[2].y=0;
pos[3].x=150;
pos[3].y=0;
pause[0]=IMG_Load("bg.png");
pause[1]=IMG_Load("save.png");
pause[2]=IMG_Load("yes.png");
pause[3]=IMG_Load("no.png");
SDL_BlitSurface(pause[0],NULL,ecran,&pos[0]);
SDL_BlitSurface(pause[1],NULL,ecran,&pos[1]);
SDL_BlitSurface(pause[2],NULL,ecran,&pos[2]);
SDL_BlitSurface(pause[3],NULL,ecran,&pos[3]);
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

            case SDL_MOUSEBUTTONDOWN:
                if (touch.button.button==SDL_BUTTON_LEFT)
                {
                    if(touch.button.x>514 && touch.button.x<628 && touch.button.y>255 && touch.button.y<304)
                     return 1;
                  
                else if(touch.button.x>455 && touch.button.x<584 && touch.button.y>408 && touch.button.y<534)
                    return 2;
                }
              break;
             }

    SDL_BlitSurface(pause[0],NULL,ecran,&pos[0]);
SDL_BlitSurface(pause[1],NULL,ecran,&pos[1]);
SDL_BlitSurface(pause[2],NULL,ecran,&pos[2]);
SDL_BlitSurface(pause[3],NULL,ecran,&pos[3]);

SDL_Flip(ecran);
}  
for (i=0;i<4;i++)
SDL_FreeSurface(pause[i]); 
return 0;             

}



/**
*@brief jouer stage 1.
*@param ecran 
*@param k volume
*@param choix choix des personnages
*@param x choix mouvements
*@param y choix mouvements
*@param nomfich fichier du sauvegarde
*@return Nothing
*

*/



void stage1(SDL_Surface* ecran, int k,int choix,int x,int y,char* nomfich,Mix_Music *musique)//fonction qui contient lerreur,appelee dans la fonction onep developpee dans menu.c
{//Enigma E;
int tab[]={0,0,0};
int continuer=1;
SDL_Surface *stage[3];
SDL_Rect position[2],positionb;
jouer_son(musique,k);
/*//Keys K;
//int ENG=2,Count=-1;
//FPS Game_fps;
intstruct(&Game_fps); // initialization Struct Game
Init_Enigma(&E);

  printf("Enigma1: %d\n",E.Selects[0]);
  printf("Enigma2: %d\n",E.Selects[1]);
  printf("Enigma3: %d\n",E.Selects[2]);
  printf("Enigma4: %d\n",E.Selects[3]);
Load_Enigma(&E,Select_Enigma(&E));
SetDefaultKeys(&K);*/
position[0].x=0;//a changer
position[0].y=0;
position[1].x=1200;
position[1].y=2;
positionb.x=0;
positionb.y=0;
stage[0]=IMG_Load("map.png");//bg
stage[1]=IMG_Load("bgcol.png");
stage[2]=IMG_Load("option/settings.png");
player p;
//SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,0,0,0));

printf("ici2\n");
SDL_BlitSurface(stage[0],NULL,ecran,&position[0]);
SDL_Flip(ecran);
initialiserp(choix,&p,x,y);
SDL_BlitSurface(stage[2],NULL,ecran,&position[1]);
SDL_BlitSurface(p.imager[0],NULL,ecran,&p.position);
SDL_Flip(ecran);
printf("ici3\n");
int b=0,i,s,j;

temps t;
 SDL_Event touch;
temps_jeu(&t);
    while(continuer)
    {    
     //printf("direc=%c",p.direction);
	//printf("position:%d",p.position.x);
   if (verifier_collision(stage[1],p.position,position[0])==1)
     {  
         if (p.direction=='r')
            p.position.x-=30;
         else if (p.direction=='l')
           p.position.x+=30;
       s+=scrolling(ecran,stage[0],&p,&position[0],p.direction);
     if (p.direction=='r')
SDL_BlitSurface(p.imager[0],NULL,ecran,&p.position);
else if (p.direction=='l')
SDL_BlitSurface(p.imagel[0],NULL,ecran,&p.position);
SDL_Flip(ecran);
     }
      if (p.direction=='r')
SDL_BlitSurface(p.imager[0],NULL,ecran,&p.position);
else if (p.direction=='l')
SDL_BlitSurface(p.imagel[0],NULL,ecran,&p.position);
SDL_Flip(ecran);
           compter_temps_stage1(&t);
           afficher_temps(t,ecran,1);
            //SDL_WaitEvent(&touch);
           while(SDL_PollEvent(&touch))
{
            switch(touch.type)
            {
            case SDL_QUIT:
                continuer=0;
                break;
             case SDL_MOUSEBUTTONDOWN:
                if (touch.button.button==SDL_BUTTON_LEFT)
                {  if(touch.button.x>1200 && touch.button.x<1290 && touch.button.y>2 && touch.button.y<86)
                    {/*j=pause(ecran); 
                     if (j==2)
                      continuer=0;
                     else if (j==1)
                       {*/sauvegarder(nomfich,p,position[0],choix,s);continuer=0;//}
                     }

                 }
                  break;

              }
     recuperer_touch(tab,touch,x,y);
     //animation(ecran,&p);
    if (tab[0]==1 && (!verifier_collision(stage[1],p.position,position[0])))
    {p.direction='l';
      animation(ecran,&p,stage[0],position[0],positionb);p.position.x-=25;s+=scrolling(ecran,stage[0],&p,&position[0],p.direction);}
    else if (tab[1]==1 && (!verifier_collision(stage[1],p.position,position[0])))
    {p.direction='r';
    animation(ecran,&p,stage[0],position[0],positionb);p.position.x+=25;s+=scrolling(ecran,stage[0],&p,&position[0],p.direction);}
    else if (tab[2]==1&& (!verifier_collision(stage[1],p.position,position[0])))
    {p.position.y-=280;
if (p.direction=='r')
p.position.x+=300;
else if (p.direction=='l')
p.position.x-=300;
s+=scrolling(ecran,stage[0],&p,&position[0],p.direction);
SDL_BlitSurface(stage[0], &position[0], ecran, &positionb);
SDL_Flip(ecran);

SDL_BlitSurface(p.imager[0], NULL, ecran, &p.position);
SDL_Flip(ecran);
SDL_Delay(100);
p.position.y+=280;
SDL_BlitSurface(stage[0], &position[0], ecran, &positionb);
SDL_Flip(ecran);}
  else if (verifier_collision(stage[1],p.position,position[0])==1)
     { 
         if (p.direction=='r')
            p.position.x-=30;
         else if (p.direction=='l')
           p.position.x+=30;
       s=scrolling(ecran,stage[0],&p,&position[0],p.direction);
     if (p.direction=='r')
SDL_BlitSurface(p.imager[0],NULL,ecran,&p.position);
else if (p.direction=='l')
SDL_BlitSurface(p.imagel[0],NULL,ecran,&p.position);
SDL_Flip(ecran);
     }

 /* else if (verifier_collision(stage[1],p.position,position[0])==2)
  {    
       if(ENG==2)
{
Next_Level(&E);
ENG=3;
}
if(ENG==1)
{
Display_Enigma(&E,ecran);
if(Count!=-1)
{
Count++;
}
if(E.Answer==-1 )
{
if(!Play_Enigma(&E,K))
Count=0;
break;
}

if(Count==50)
{
if(E.Correct_Answer!=E.Answer)
break;

else 
E.Score++;

Free_Enigma(E);
ReInit_Enigma(&E);
printf("\nTry:%d\n",E.Try);
Load_Enigma(&E,Select_Enigma(&E));
printf("\nLevel:%d\n",E.Level);
Count=-1;
}
}


SDL_Flip(ecran);*/

   


            } 
            if (verifier_collision(stage[1],p.position,position[0])==1)
     {  
         if (p.direction=='r')
            p.position.x-=30;
         else if (p.direction=='l')
           p.position.x+=30;
       s+=scrolling(ecran,stage[0],&p,&position[0],p.direction);
    if (p.direction=='r')
SDL_BlitSurface(p.imager[0],NULL,ecran,&p.position);
else if (p.direction=='l')
SDL_BlitSurface(p.imagel[0],NULL,ecran,&p.position);
SDL_Flip(ecran);
     }
SDL_BlitSurface(stage[0],&position[0],ecran,&positionb);
SDL_BlitSurface(stage[2],NULL,ecran,&position[1]);
SDL_Delay(50);
if (p.direction=='r')
SDL_BlitSurface(p.imager[0],NULL,ecran,&p.position);
else if (p.direction=='l')
SDL_BlitSurface(p.imagel[0],NULL,ecran,&p.position);
SDL_Flip(ecran);
}
for (i=0;i<2;i++)
SDL_FreeSurface(stage[i]);
for (i=0;i<4;i++)
{SDL_FreeSurface(p.imager[i]);
SDL_FreeSurface(p.imagel[i]);}
}



/**
*@brief initiliser personnage .
*@param choix choix des personnages
*@param p joeur
*@return Nothing
*

*/




void initload(int choix,player *p)
{
if (choix==1)
{printf("nadhir \n");
p->imager[0]=IMG_Load("Image/nadhir.png");
p->imager[1]=IMG_Load("Image/nadhir.png");
p->imager[2]=IMG_Load("Image/nadhir.png");
p->imager[3]=IMG_Load("Image/nadhir.png");
p->imagel[0]=IMG_Load("Image/nadhir.png");
p->imagel[1]=IMG_Load("Image/nadhir.png");
p->imagel[2]=IMG_Load("Image/nadhir.png");
p->imagel[3]=IMG_Load("Image/nadhir.png");
}
else if (choix==3)
{printf("hichri \n");
p->imager[0]=IMG_Load("Image/hichri.png");
p->imager[1]=IMG_Load("Image/hichri.png");
p->imager[2]=IMG_Load("Image/hichri.png");
p->imager[3]=IMG_Load("Image/hichri.png");
p->imagel[0]=IMG_Load("Image/hichri.png");
p->imagel[1]=IMG_Load("Image/hichri.png");
p->imagel[2]=IMG_Load("Image/hichri.png");
p->imagel[3]=IMG_Load("Image/hichri.png");
}
else if (choix==4)
{printf("malek \n");
p->imager[0]=IMG_Load("Image/malek.png");
p->imager[1]=IMG_Load("Image/malek.png");
p->imager[2]=IMG_Load("Image/malek.png");
p->imager[3]=IMG_Load("Image/hichri.png");
p->imagel[0]=IMG_Load("Image/hichri.png");
p->imagel[1]=IMG_Load("Image/hichri.png");
p->imagel[2]=IMG_Load("Image/hichri.png");
p->imagel[3]=IMG_Load("Image/hichri.png");
}
else if (choix==2)
{printf("wassim \n");
p->imager[0]=IMG_Load("was1.png");
p->imager[1]=IMG_Load("was2.png");
p->imager[2]=IMG_Load("was3.png");
p->imager[3]=IMG_Load("was4.png");
p->imagel[0]=IMG_Load("Wassim1.png");
p->imagel[1]=IMG_Load("Wassim2.png");
p->imagel[2]=IMG_Load("Wassim3.png");
p->imagel[3]=IMG_Load("Wassim4.png");
printf("ici\n");
}
}






/**
*@brief load stage 1.
*@param ecran 
*@param p joeur
*@param t temps restant
*@param pos position camera
*@param nomfich fichier du sauvegarde
*@param choix choix des personnages
*@return Nothing
*

*/


void loadstage1(SDL_Surface *ecran,player p,char* nomfich,int choix,int x,int y,int s,int k,Mix_Music *musique)
{
int tab[]={0,0,0};
int continuer=1;
jouer_son(musique,k);
SDL_Surface *stage[3];
SDL_Rect position[2],positionb,positionbgg;
printf("x=%d \n",x);
printf("y=%d \n",y);
position[0].x=200;//a changer
position[0].y=0;
position[1].x=1200;
position[1].y=2;
positionb.x=0;
positionb.y=0;
positionbgg.x=200;
positionbgg.y=0;
stage[0]=IMG_Load("map.png");//bg
stage[1]=IMG_Load("bgcol.png");
stage[2]=IMG_Load("option/settings.png");
//SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,0,0,0));

printf("ici2\n");
//SDL_BlitSurface(stage[0],NULL,ecran,&positionb);
SDL_BlitSurface(stage[0],&positionbgg,ecran,&positionb);
//SDL_Flip(ecran);
initload(choix,&p);
//initialiserp(choix,&p,x,y);
SDL_BlitSurface(stage[2],NULL,ecran,&position[1]);
SDL_Flip(ecran);
if(p.direction=='r')
SDL_BlitSurface(p.imager[0],NULL,ecran,&p.position);
else
SDL_BlitSurface(p.imagel[0],NULL,ecran,&p.position);
SDL_Flip(ecran);
printf("ici3\n");
int b=0,i,j;


 SDL_Event touch;

    while(continuer)
    {    
     //printf("direc=%c",p.direction);
	//printf("position:%d",p.position.x);
   if (verifier_collision(stage[1],p.position,position[0])==1)
     {  
         if (p.direction=='r')
            p.position.x-=30;
         else if (p.direction=='l')
           p.position.x+=30;
       s+=scrolling(ecran,stage[0],&p,&position[0],p.direction);
     if (p.direction=='r')
SDL_BlitSurface(p.imager[0],NULL,ecran,&p.position);
else if (p.direction=='l')
SDL_BlitSurface(p.imagel[0],NULL,ecran,&p.position);
SDL_Flip(ecran);
     }
      if (p.direction=='r')
SDL_BlitSurface(p.imager[0],NULL,ecran,&p.position);
else if (p.direction=='l')
SDL_BlitSurface(p.imagel[0],NULL,ecran,&p.position);
SDL_Flip(ecran);
           //compter_temps_stage1(&t);
           //afficher_temps(t,ecran,1);
            //SDL_WaitEvent(&touch);
           while(SDL_PollEvent(&touch))
{
            switch(touch.type)
            {
            case SDL_QUIT:
                continuer=0;
                break;
             case SDL_MOUSEBUTTONDOWN:
                if (touch.button.button==SDL_BUTTON_LEFT)
                {  if(touch.button.x>1200 && touch.button.x<1290 && touch.button.y>2 && touch.button.y<86)
                    {/*j=pause(ecran); 
                     if (j==2)
                      continuer=0;
                     else if (j==1)
                       {*/sauvegarder(nomfich,p,position[0],choix,s);continuer=0;//}
                     }

                 }
                  break;

              }
     recuperer_touch(tab,touch,p.x,p.y);
     //animation(ecran,&p);
    if (tab[0]==1 && (!verifier_collision(stage[1],p.position,position[0])))
    {p.direction='l';
      animation(ecran,&p,stage[0],position[0],positionb);p.position.x-=25;s+=scrolling(ecran,stage[0],&p,&position[0],p.direction);}
    else if (tab[1]==1 && (!verifier_collision(stage[1],p.position,position[0])))
    {p.direction='r';
    animation(ecran,&p,stage[0],position[0],positionb);p.position.x+=25;s+=scrolling(ecran,stage[0],&p,&position[0],p.direction);}
    else if (tab[2]==1&& (!verifier_collision(stage[1],p.position,position[0])))
    {p.position.y-=280;
if (p.direction=='r')
p.position.x+=300;
else if (p.direction=='l')
p.position.x-=300;
s+=scrolling(ecran,stage[0],&p,&positionbgg,p.direction);
SDL_BlitSurface(stage[0], &positionbgg, ecran, &positionb);
SDL_Flip(ecran);

SDL_BlitSurface(p.imager[0], NULL, ecran, &p.position);
SDL_Flip(ecran);
SDL_Delay(100);
p.position.y+=280;
SDL_BlitSurface(stage[0], &position[0], ecran, &positionb);
SDL_Flip(ecran);}
  else if (verifier_collision(stage[1],p.position,position[0])==1)
     { 
         if (p.direction=='r')
            p.position.x-=30;
         else if (p.direction=='l')
           p.position.x+=30;
       s=scrolling(ecran,stage[0],&p,&position[0],p.direction);
     if (p.direction=='r')
SDL_BlitSurface(p.imager[0],NULL,ecran,&p.position);
else if (p.direction=='l')
SDL_BlitSurface(p.imagel[0],NULL,ecran,&p.position);
SDL_Flip(ecran);
     }
   


            } 
            if (verifier_collision(stage[1],p.position,position[0])==1)
     {  
         if (p.direction=='r')
            p.position.x-=30;
         else if (p.direction=='l')
           p.position.x+=30;
       s+=scrolling(ecran,stage[0],&p,&position[0],p.direction);
    if (p.direction=='r')
SDL_BlitSurface(p.imager[0],NULL,ecran,&p.position);
else if (p.direction=='l')
SDL_BlitSurface(p.imagel[0],NULL,ecran,&p.position);
SDL_Flip(ecran);
     }
SDL_BlitSurface(stage[0],&position[0],ecran,&positionb);
SDL_BlitSurface(stage[2],NULL,ecran,&position[1]);
SDL_Flip(ecran);
SDL_Delay(50);
if (p.direction=='r')
SDL_BlitSurface(p.imager[0],NULL,ecran,&p.position);
else if (p.direction=='l')
SDL_BlitSurface(p.imagel[0],NULL,ecran,&p.position);
SDL_Flip(ecran);
}
for (i=0;i<2;i++)
SDL_FreeSurface(stage[i]);
for (i=0;i<4;i++)
{SDL_FreeSurface(p.imager[i]);
SDL_FreeSurface(p.imagel[i]);}

}




































