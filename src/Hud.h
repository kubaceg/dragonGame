#ifndef __HUD_H__
#define __HUD_H__
#include "SDL.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_gfxPrimitives.h"
#include <cstdio>
#include <cstdlib>
using namespace std;

class Hud
{
private:
    SDL_Surface* screen;
    TTF_Font* font;
    SDL_Color color;
    SDL_Rect position;
    TTF_Font* loadfont(char* file, int ptsize);
    SDL_Surface* drawtext(TTF_Font* font, SDL_Color color, char text[]);
    void drawPoints(int points);
    void drawAmmoBar(int ammo);

public:
    void draw(int points, int ammo);
    Hud(SDL_Surface* sc);
};
#endif
