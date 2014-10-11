#ifndef __FLAMES_H__
#define __FLAMES_H__
#include "SDL.h"
#include "SDL/SDL_image.h"
#include <list>
using namespace std;

class Flames
{
private:
    int position, frameCount;
    list<SDL_Rect> flames;
    SDL_Rect flamePosition;
    SDL_Surface* flame;
    SDL_Surface* screen;

public:
    void draw();
    void shot(SDL_Rect *dragonPosition);
    Flames(SDL_Surface* sc);
    list<SDL_Rect>* getFlamePositions();
};
#endif