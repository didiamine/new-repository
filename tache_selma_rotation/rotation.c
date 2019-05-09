#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_rotozoom.h>

 
#define TEMPS       30 // Le temps qu'il y a entre chaque augmentation de l'angle.
 
int main(int argc, char *argv[])
{
    SDL_Surface *ecran = NULL, *image = NULL, *rotation = NULL;
    SDL_Rect rect;
    SDL_Event event;
    double angle = 0;
 
    int continuer = 1;
    int tempsPrecedent = 0, tempsActuel = 0;
 
    SDL_Init(SDL_INIT_VIDEO);
 
    ecran = SDL_SetVideoMode(500, 500, 32, SDL_HWSURFACE);
    SDL_WM_SetCaption("Faire des rotations avec SDL_gfx", NULL);
 
    image =  IMG_Load("image.png");
 
    rect.x =  150;
    rect.y =  150;
 
    while(continuer)
    {
        SDL_PollEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
                break;
        }
 
        tempsActuel = SDL_GetTicks();
        if (tempsActuel - tempsPrecedent > TEMPS)
        {
            angle += 2; //On augmente l'angle pour que l'image tourne sur elle-m�me.
 
            tempsPrecedent = tempsActuel;
        }
        else
        {
            SDL_Delay(TEMPS - (tempsActuel - tempsPrecedent));
        }
 
 
        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
 
        rotation = rotozoomSurface(image, angle, 1.0, 1); //On transforme la surface image.
 
        SDL_BlitSurface(rotation , NULL, ecran, &rect); //On affiche la rotation de la surface image.
        SDL_FreeSurface(rotation); //On efface la surface rotation car on va la red�finir dans la prochaine boucle. Si on ne le fait pas, cela cr�e une fuite de m�moire. 
 
        SDL_Flip(ecran);
    }
 
    SDL_FreeSurface(ecran);
    SDL_FreeSurface(image);
    SDL_Quit();
 
    return EXIT_SUCCESS;
}
