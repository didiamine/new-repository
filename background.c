#include <stdio.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <stdlib.h>
#include "SDL/SDL_mixer.h"
#include <time.h>
#define SCREEN_W 600
#define SCREEN_H 580
int aabb(SDL_Rect posperso,SDL_Rect PositionEnemy2);

void main(SDL_Surface *image,SDL_Surface *screen,SDL_Rect positionecran,SDL_Surface *button,SDL_Event event,SDL_Surface *enemy2)
{

int x=500;
int y=600;
SDL_Rect PositionEnemy2;
SDL_Rect camera;
SDL_Surface *perso;
SDL_Rect posperso;
char pause;
//Mix_Music *music;
if (SDL_Init(SDL_INIT_VIDEO)!=0)
{
printf("Unable to initialize SDL: %s\n",SDL_GetError());
}
screen=SDL_SetVideoMode(SCREEN_W,SCREEN_H,32,SDL_HWSURFACE|SDL_DOUBLEBUF);


if (screen==NULL)
{
printf("Unable to set video mode: %s\n",SDL_GetError());

}


image = IMG_Load("ynaan.jpg");
if (image==NULL)
{
printf("Unable to load bitmap: %s\n",SDL_GetError());

}


perso = IMG_Load("1.png");
if (perso==NULL)
{
printf("Unable to load bitmap: %s\n",SDL_GetError());

}

enemy2 = IMG_Load("enemy2.png");
if (enemy2==NULL)
{
printf("Unable to load bitmap: %s\n",SDL_GetError());

}

posperso.x=620;
posperso.y=420;

PositionEnemy2.x = 20;
PositionEnemy2.y = 420;

positionecran.x = 0;
positionecran.y = 0;
positionecran.w = image->w;
positionecran.h = image->h;
camera.x=0;
camera.y=0;
camera.h=SCREEN_H;
camera.w=SCREEN_W;




if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
{
printf("%s",Mix_GetError());
}

Mix_Music *music;
music=Mix_LoadMUS("music.mp3");
Mix_PlayMusic(music,-1);

int done=1;
while (done)
{
SDL_BlitSurface(image,&camera,screen,&positionecran);
SDL_BlitSurface(enemy2,NULL,screen,&PositionEnemy2);
SDL_BlitSurface(perso,NULL,screen,&posperso);
SDL_Flip(screen);
if(aabb(posperso,PositionEnemy2)==1){printf("aabb \n");}
//music=Mix_LoadMUS("music.mp3");
  //Mix_PlayMusic(music,-1);
while (SDL_PollEvent(&event))
{
switch (event.type)
{

 case SDL_QUIT:
done=0;
break;
case SDL_MOUSEBUTTONDOWN:
{
    switch (event.button.button)
    {
case SDL_BUTTON_LEFT:
PositionEnemy2.x -=50;
camera.x -= 120;
if(PositionEnemy2.x<0) 
{
  PositionEnemy2.x=0;
  camera.x=0;
}
break;

case SDL_BUTTON_RIGHT:
PositionEnemy2.x +=50;
camera.x += 120;
if(PositionEnemy2.x>1200) 
{
  PositionEnemy2.x=1200;
  camera.x=1200;
}
}
}
case SDL_KEYDOWN:
{

switch(event.key.keysym.sym)
{
case  SDLK_ESCAPE:
done = 1;
break;
case SDLK_LEFT:
PositionEnemy2.x -= 15;
camera.x -= 75;
posperso.x +=75;
if(PositionEnemy2.x<0) 
{
  PositionEnemy2.x=0;
  camera.x=0;
}
break;
case SDLK_RIGHT:
PositionEnemy2.x += 15;
camera.x += 75;
posperso.x -=75;
if(PositionEnemy2.x>1200) 
{
  PositionEnemy2.x=1200;
  camera.x=1200;
}
break;
case SDLK_UP:
PositionEnemy2.y -= 35;
break;
case SDLK_DOWN:
PositionEnemy2.y += 15;
}
}
break;
case SDL_KEYUP:
{
switch(event.key.keysym.sym)
{


case SDLK_UP:
if (PositionEnemy2.y < 220)
PositionEnemy2.y += 35;
break;
case SDLK_DOWN:
if (PositionEnemy2.y > 220)
PositionEnemy2.y -= 15;

}
}
}
}
}

if(camera.x>1200-600)
{
camera.x=600; 
PositionEnemy2.x=600-72;
}

Mix_FreeMusic(music);
SDL_FreeSurface(image);
SDL_FreeSurface(enemy2);
SDL_FreeSurface(perso);
}
int aabb(SDL_Rect posperso,SDL_Rect PositionEnemy2){
	
	if((PositionEnemy2.y>=posperso.y+posperso.h)||(PositionEnemy2.x>=posperso.x+posperso.w)||(PositionEnemy2.x+PositionEnemy2.w<=posperso.x)||(PositionEnemy2.y+PositionEnemy2.h<=posperso.y))
	{return 0;}
	else{return 1;}
}
