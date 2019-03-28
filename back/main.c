#include <stdio.h>
#include <stdlib.h>
#include "back.h"
#include "/usr/include/SDL/SDL.h"
#include "/usr/include/SDL/SDL_image.h"

int main(void)
{
back b;
SDL_Surface *screen;

init_back(b);
aff_back(b);


return 0;
}

