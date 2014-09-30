#ifndef __HUD_H__
#define __HUD_H__
#include "SDL.h"
#include "SDL/SDL_ttf.h"
#include <cstdio>
#include <cstdlib>
using namespace std;

class Hud
{
private:
    SDL_Surface* screen, text;
    TTF_Font* font;
    SDL_Color color;
    TTF_Font* loadfont(char* file, int ptsize);
    SDL_Surface* drawtext(TTF_Font* fonttodraw, char fgR, char fgG, char fgB, char fgA, char bgR, char bgG, char bgB, char bgA, char text[]);

public:
    void draw(int points);
    Hud(SDL_Surface* sc);
};
#endif
