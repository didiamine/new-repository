#ifndef BACK_H
#define BACK_H

struct back
{

SDL_Surface *image;

SDL_Event event;
SDL_Rect positionecran;
};
typedef struct back back;
back b;
int init_back(back b);
int aff_back(back b);

#endif
