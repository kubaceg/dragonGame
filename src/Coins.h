#ifndef __COINS_H__
#define __COINS_H__
#include "SDL.h"
#include "SDL/SDL_image.h"
#include <list>
#include <cstdlib>
using namespace std;

class Coins
{
private:
    int position, frameCount, flameX, flameYmin, flameY, points, level;
    list<SDL_Rect> coinsPosition;
    SDL_Surface* coin[9];
    SDL_Surface* screen;
    void generateCoin();
    int generateCoinYPosition();

public:
    void draw();
    int detectColision(list<SDL_Rect> *flames);
    Coins(SDL_Surface* sc);
};
#endif
