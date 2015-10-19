#ifndef __DRAGON_H__
#define __DRAGON_H__
#include "SDL.h"

class Dragon
{
private:
    int position, frameCount;
    SDL_Rect dragon[7];
    SDL_Rect destination;
    SDL_Surface* bitmap;
    SDL_Surface* screen;

public:
    void draw();
    void move(SDL_Rect *pos);
    Dragon(SDL_Surface* sc);
};
#endif