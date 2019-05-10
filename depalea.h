#ifndef FONCTIONS_H_
#define FONCTIONS_H_

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <time.h>



typedef struct
{

SDL_Rect  position_lion;
SDL_Surface * image_lion;
SDL_Rect positionmax_lion;
SDL_Rect positionmin_lion;


}lion;



void initialiser_enemy(lion *E);
int position_aleatoire(int positionmax_lion,int positionmin_lion);
void deplacement_aleatoire(lion  E,SDL_Surface*screen);



















































#endif /* FONCTIONS_H_ */
