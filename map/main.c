#include "player.h"



int main (void)
{
SDL_Surface *ecran =NULL;
SDL_Surface *map = NULL;
SDL_Rect positionmap;
	pers p;
point po;
    SDL_Init(SDL_INIT_VIDEO);
ecran = SDL_SetVideoMode(1366, 768, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption("annimation joueur", NULL);
if (ecran==NULL)
{
printf("error: %s ",SDL_GetError());
exit(EXIT_FAILURE);
}
map = IMG_Load("map1.png");
 positionmap.x=100;
    positionmap.y=100;

    SDL_EnableKeyRepeat(10, 10);

point poi;
initialiserperso( &p);
SDL_BlitSurface(map, NULL, ecran, &positionmap);

mouvement(p,po,ecran);
liberer_surface2(&po);
liberer_surface(&p);
SDL_Quit();
    return EXIT_SUCCESS;
}
