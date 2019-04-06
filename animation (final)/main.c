#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <string.h>
#include "animation.h"

int main()
{char ch='r';
SDL_Rect pr[3],pl[3];

set_clips(80,90,pr,pl);

animation(pr,pl,ch);



return 0;
}
