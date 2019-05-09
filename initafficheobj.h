#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>


typedef struct
{
SDL_Surface *image ;
SDL_Rect pos ;

} Objet ;




void initialiserObj( Objet *obj , char name[] , int x , int y ) ;
void affichageObj ( Objet *obj , SDL_Surface *screen) ;
