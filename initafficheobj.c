#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "initafficheobj.h"
void initialiserObj( Objet *obj , char name[] , int x , int y )

{



	       obj->image =  IMG_Load(name);

	      if  ( obj->image  ==  NULL )  {

         printf ( "Can not load image of tux: %s \n " , SDL_GetError ());

         exit ( 1 );

     }

     else

     {



     obj->pos.x  =  x ;

     obj->pos.y  =  y ;

     obj->pos.h  =  obj->image->h ;

     obj->pos.w  =  obj->image->w ;

}

SDL_SetColorKey(obj->image, SDL_SRCCOLORKEY, SDL_MapRGB(obj->image->format, 255, 255, 255));



}



void affichageObj ( Objet *obj , SDL_Surface *screen)

{



SDL_BlitSurface(obj->image, NULL, screen, &(obj->pos));


SDL_Flip(screen);



}
