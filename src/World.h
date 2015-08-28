#ifndef __WORLD_H__
#define __WORLD_H__
#include "SDL.h"
#include "Clouds.h"

class World
{
private:
    SDL_Surface* screen;
    int frameCount;
    Clouds *clouds;

public:
    void draw();
    World(SDL_Surface* sc);
};
#endif