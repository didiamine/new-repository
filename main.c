#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"SDL/SDL.h"
#include"SDL/SDL_image.h"
#include"SDL/SDL_mixer.h"
#include"depalea.h"

int  main()
{

SDL_Surface*screen;
SDL_Rect positionecran;
SDL_Event event;



lion E;


    SDL_Init(SDL_INIT_VIDEO);
    

    screen = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption("Afficher Ennemie en Mvt Aleatoire Va et Vient sur x", NULL);
 initialiser_lion(&E);
   

deplacement_aleatoire(E,screen);

  SDL_FreeSurface(E.image_lion);
    SDL_Quit();




}
