#include <stdio.h>
#include <SDL/SDL.h>
#include <time.h>
#include <math.h>
#include <SDL/SDL_image.h>
#include "initafficheobj.h"
void main(){


SDL_Rect pos;
pos.x=0;
pos.y=0;

Objet *obj;

SDL_Surface *screen=NULL,*background=NULL;
screen = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE);

background=IMG_Load("background.png");
SDL_BlitSurface(background,NULL, screen,&pos);


 initialiserObj(obj ,"1.png" ,-250 , -175) ; 
    

affichageObj (obj ,screen) ;

SDL_Delay(4000);


SDL_Flip(screen);

SDL_Quit();

}



