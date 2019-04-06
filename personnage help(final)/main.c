#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <string.h>
#include "help.h"

int main ()
{ help p;
 initialiser_persHelp(&p);
afficher_persHelp(p);

return 0;
}

