#ifndef PROJECT_FONTHELPER_H
#define PROJECT_FONTHELPER_H

#include "SDL.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_gfxPrimitives.h"
#include <cstdio>
#include <cstdlib>

using namespace std;


class FontHelper {
protected:
    SDL_Surface *screen;
    SDL_Color color;
    SDL_Rect position;
    TTF_Font *font;


    TTF_Font *loadFont(char *file, int ptsize);

    SDL_Surface *drawText(TTF_Font *font, SDL_Color color, char text[]);

public:
    FontHelper(SDL_Surface *sc);
};


#endif
