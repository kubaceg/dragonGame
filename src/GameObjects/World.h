#ifndef __WORLD_H__
#define __WORLD_H__

#include "SDL.h"
#include "Clouds.h"

class World {
private:
    SDL_Surface *screen;
    SDL_Surface *background;
    SDL_Rect bgPosition;
    int frameCount;

public:
    void draw();

    World(SDL_Surface *sc);
};

#endif