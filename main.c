#include<stdio.h>

#include<stdlib.h>

#include<string.h>

#include<time.h>

#include"SDL/SDL.h"

#include"SDL/SDL_image.h"

#include"SDL/SDL_mixer.h"

#include"depalea.h"



void  main()

{





enemy *E;

    SDL_Init(SDL_INIT_VIDEO);




SDL_Surface *screen=NULL;
    screen = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);

    

 initialiser_enemy(E);

deplacement_aleatoire(E,screen);


  SDL_FreeSurface(E->image_enemy);
 
    SDL_Quit();


}
