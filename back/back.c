#include "/usr/include/SDL/SDL.h"
#include "/usr/include/SDL/SDL_image.h"
#include <stdio.h>
#include <stdlib.h>
#include "back.h"

SDL_Surface *screen;
SDL_Surface *image;

SDL_Event event;
SDL_Rect positionecran;

int init_back(back b)
{




if (SDL_Init(SDL_INIT_VIDEO)!=0)
{
printf("Unable to initialize SDL: %s\n",SDL_GetError());
return 1;
}
screen=SDL_SetVideoMode(960,540,32,SDL_HWSURFACE|SDL_DOUBLEBUF);


if (screen==NULL)
{
printf("Unable to set video mode: %s\n",SDL_GetError());
return 1;
}


image = IMG_Load("back2.png");
if (image==NULL)
{
printf("Unable to load bitmap: %s\n",SDL_GetError());
return 1;
}
return 0;
}

int aff_back(back b)
{

positionecran.x = 0;
positionecran.y = 0;
positionecran.w = image->w;
positionecran.h = image->h;



int done=1;
while (done)
{

SDL_BlitSurface(image,NULL,screen,&positionecran);

SDL_Flip(screen);

while (SDL_PollEvent(&event))
{
switch (event.type)
{
case SDL_QUIT:
done=0;
break;

case SDL_KEYDOWN:
{

switch(event.key.keysym.sym)
{
case  SDLK_ESCAPE:
done = 0;

}
}
}
}
}



return 0;
}

