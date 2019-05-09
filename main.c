#include "player.h"

int main (void)
{
SDL_Surface *ecran =NULL;
	pers p;

    SDL_Init(SDL_INIT_VIDEO);
ecran = SDL_SetVideoMode(1366, 768, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption("annimation joueur", NULL);

if (ecran==NULL)
{
printf("error: %s ",SDL_GetError());
exit(EXIT_FAILURE);
}


initialiserperso( &p);
mouvement(p,ecran);
liberer_surface(&p);
SDL_Quit();
    return EXIT_SUCCESS;
}
