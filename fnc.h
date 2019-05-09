
#ifndef FNC_H_
#define FNC_H_
/**
* @struct minimap
* @brief struct for minimap
*/

typedef struct image
{
	SDL_Surface *img;
	SDL_Rect pos;
}image;

image init_image(char nameofpicture[100],int x,int y);
void affichage(SDL_Surface *ecran,image img);
void librer_image(image img);


#endif
