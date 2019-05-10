#include"depalea.h"
#include<stdio.h>
#include"SDL/SDL.h"
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include<time.h>


void initialiser_lion(lion* E)
{
    E->position_lion.x = 0;
    E->position_lion.y = 0;
    E->image_lion = IMG_Load("lion.jpg");
    SDL_SetColorKey(E->image_lion, SDL_SRCCOLORKEY, SDL_MapRGB(E->image_lion->format, 0, 0, 255));
     E->positionmin_lion.x=0;
  E->positionmax_lion.x=40;

}






int position_aleatoire(int positionmax,int positionmin)
{
int pos;
 srand(time(NULL));
pos=rand()%(positionmax-positionmin+1)+positionmin;


return pos;
}





void deplacement_aleatoire(lion E,SDL_Surface *screen)
{
SDL_Event event;

int continuer = 1;
int tempsPrecedent = 0, tempsActuel = 0;

int pos;
static int k=0;
    
char temps[20];


E.positionmax_lion.x=screen->w / 2 ;//- E.image_enemy->w / 2;

pos=position_aleatoire(E.positionmax_lion.x,E.positionmin_lion.x);



    SDL_EnableKeyRepeat(10, 10);

    while (continuer)
    {
        SDL_PollEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
                break;
        }

        tempsActuel = SDL_GetTicks();



        if (tempsActuel - tempsPrecedent > 30)         {
           
               if(k==0)

                   {
                     if(E.position_lion.x<pos)/*positionmax)*/
                          {
                            E.position_lion.x++;

                          }
                     else k=1;

                   }
              if(k==1)
                  {
                    if(E.position_lion.x>E.positionmin_lion.x)
                            E.position_lion.x--;
                    else
                         k=0;
                  }             
                                    
            tempsPrecedent = tempsActuel; 
        }




        SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
        SDL_BlitSurface(E.image_lion, NULL, screen, &(E.position_lion));
        SDL_Flip(screen);
    }

   
   

}
