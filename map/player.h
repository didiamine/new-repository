#ifndef PLAYER_H_
#define PLAYER_H_

#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>

/**
* @struct personnage
* @brief struct for personnage
*/

struct personnage
{
    SDL_Surface *bas;
    SDL_Surface *haut;
    SDL_Surface *gauche[8];
    SDL_Surface *droite[8];
    SDL_Surface *depart;
    int left,right;

    SDL_Rect position_joueur;
	int score;
	int vie;
};
typedef struct personnage pers;



struct point
{ SDL_Surface* image;
  SDL_Surface* poi;
SDL_Surface *bas;
    SDL_Surface *haut;
  SDL_Surface* depart;
  SDL_Rect position_point;
int left,right;
 SDL_Surface *gauche[1];
    SDL_Surface *droite[1];
};
typedef struct point point ; 




void initialiserperso(pers *p);
void afficherperso(pers *p,int d,SDL_Surface *ecran);
void mouvement(pers p,point po,SDL_Surface *ecran);
pers boujer(int d, pers p);
void liberer_surface(pers *p);
void initialiserpoint(point *po);
point boujer2(int d, point po);
void afficherpoint(point *po,int d,SDL_Surface *ecran);
void liberer_surface2(point *po);

void updateHeroScore(pers* p, int HE_collision);



#endif
