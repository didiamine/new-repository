#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h> 
#include <SDL/SDL_image.h> 
#define SCREEN_W 800
#define SCREEN_H 800

int main()
{
    Mix_Music *musique; 
    int continuer = 1; 
    SDL_Surface *ecran = NULL, *imageDeFond = NULL,*imageDeFond1 = NULL, *perso = NULL,*perso1 = NULL; 

 int game =1,directionSDL1,directionSDL2;

    SDL_Event event; 

    SDL_Rect positionperso,positionperso1; 
    SDL_Rect positionFond,positionFond1; 
    SDL_Rect camera,camera1;
    camera.x=0;
    camera.y=0;
    camera.h=300;
    camera.w=SCREEN_W;

    camera1.x=0;
    camera1.y=0;
    camera1.h=300;
    camera1.w=SCREEN_W;


    positionFond.x = 0; 
    positionFond.y = 0; 
    positionFond1.x = 0; 
    positionFond1.y = 300; 

    positionperso.x = 0; 
    positionperso.y = 140; 
  positionperso1.x = 0; 
    positionperso1.y = 420; 

    SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO); 

  
    SDL_WM_SetCaption("mouvement", NULL);
   
    ecran = SDL_SetVideoMode(SCREEN_W, SCREEN_H, 32, SDL_HWSURFACE | SDL_RESIZABLE);
    

    if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
    
        printf ("%s",Mix_GetError());

    Mix_VolumeMusic(MIX_MAX_VOLUME / 1); 
    musique =Mix_LoadMUS("music.mp3");
    Mix_PlayMusic(musique,-1);

    perso = IMG_Load("detective.png");
   perso1 = IMG_Load("detective.png");
    SDL_SetColorKey(perso, SDL_SRCCOLORKEY, SDL_MapRGB(perso->format, 255, 255, 255));

 SDL_SetColorKey(perso1, SDL_SRCCOLORKEY, SDL_MapRGB(perso->format, 255, 255, 255));


    imageDeFond = IMG_Load("back.png");
imageDeFond1 = IMG_Load("back.png"); 
 // printf ("%d"m);
    SDL_EnableKeyRepeat(100,100); 

    while(continuer) 
    {
       

        SDL_WaitEvent(&event); 
        switch(event.type)
        {
        case SDL_QUIT: 
            continuer = 0; 
        case SDL_KEYDOWN: 
            switch(event.key.keysym.sym)
            {

            case SDLK_ESCAPE: 
                continuer = 0;
                break;

            case SDLK_LEFT: // Flèche gauche

                positionperso.x -= 20; 
                camera.x -= 20;

                if(positionperso.x<0) 
                {
                    positionperso.x=0;
                    camera.x=0;
                }
                break;

   case SDLK_q: // Flèche gauche

                positionperso1.x -= 20; 
                camera1.x -= 20;

                if(positionperso1.x<0) 
                {
                    positionperso1.x=0;
                    camera1.x=0;
                }
                break;

            case SDLK_RIGHT: // Flèche droite

                positionperso.x += 20; 
                 camera.x += 20;
                if(positionperso.x>1600)
                {
                    positionperso.x=1600;
                    camera.x=1600;
                }
                break;

   case SDLK_d: // Flèche droite

                positionperso1.x += 20; 
                 camera1.x += 20;
                if(positionperso1.x>1600)
                {
                    positionperso1.x=1600;
                    camera1.x=1600;
                }
                break;
   case SDLK_s://flèche bas
               positionperso1.y+=20;
               if(positionperso1.y>420)
               {
                  positionperso1.y=420;
               }
                break;
            case SDLK_DOWN: // Flèche bas

                positionperso.y += 20; 
                if(positionperso.y>140)
                {
                    positionperso.y=140;
                }
                break;

            case SDLK_UP: // Flèche haut

                positionperso.y -= 20; 
                if(positionperso.y<110)
                {
                    positionperso.y=110;
                }
                break;
            case SDLK_z: //flèche haut deuxiéme personnage
                positionperso1.y -= 20; 
                if(positionperso1.y<370)
                {
                    positionperso1.y=370;
                }
                break;
             
}
break;



  /*         case SDL_MOUSEBUTTONDOWN:

                if(event.button.button==SDL_BUTTON_LEFT)
                {
                    positionperso.x -= 20;      
                    camera.x -= 20;   
                if(positionperso.x<0) // fixation de la Position 
                {
                    positionperso.x=0;
                    camera.x=0;
                }  
             
                }
                if(event.button.button==SDL_BUTTON_RIGHT)
                {
                    positionperso.x += 20;
                    camera.x += 20;
                if(positionperso.x>1600)// fixation de la Position
                {
                    positionperso.x=1600;
                    camera.x=1600;
                }

                }
                break;  
*/
            }

      /*      if(camera.x>1600-800)
            {
             camera.x=800; 
             positionperso.x=800-72;
            }
 

     */  
SDL_BlitSurface(imageDeFond,&camera, ecran, &positionFond); 

    SDL_BlitSurface(imageDeFond1,&camera1, ecran, &positionFond1); 
                 
  SDL_BlitSurface(perso, NULL, ecran, &positionperso);
  SDL_BlitSurface(perso1, NULL, ecran, &positionperso1); 




            SDL_Flip(ecran);   

        }
    SDL_FreeSurface(perso); 
    Mix_FreeMusic(musique); 
    Mix_CloseAudio(); 
    SDL_Quit(); 
    return EXIT_SUCCESS; 
}



