#ifndef __WORLD_H__
#define __WORLD_H__
#include "SDL.h"

class World
{
private:
    SDL_Rect destination[5];
    SDL_Surface* cloud[5];
    SDL_Surface* screen;
    int frameCount;

public:
    void draw();
    void move();
    World(SDL_Surface* sc);
};
#endif