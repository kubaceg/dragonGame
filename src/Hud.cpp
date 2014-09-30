#include "Hud.h"

Hud::Hud(SDL_Surface *sc)
{
    screen = sc;
    font = loadfont("graph/Aller_Rg.ttf", 60);
    color = {255, 255, 255};
}

void Hud::draw(int points)
{
    SDL_Surface *text;
    SDL_Rect offset;
    offset.x = 10;
    offset.y = 10;
    char str[5];

    sprintf(str, "%d", points);
    SDL_Surface* surface = drawtext(font, 255, 255, 255, 70, 0, 0, 0, 0, str);

    SDL_BlitSurface(surface, NULL, screen, NULL);
}

SDL_Surface* Hud::drawtext(TTF_Font* fonttodraw, char fgR, char fgG, char fgB, char fgA, 
        char bgR, char bgG, char bgB, char bgA, char text[])
{
    SDL_Color tmpfontcolor = {fgR,fgG,fgB,fgA};
    SDL_Color tmpfontbgcolor = {bgR, bgG, bgB, bgA};
    SDL_Surface* resulting_text;

    resulting_text = TTF_RenderText_Solid(fonttodraw, text, tmpfontcolor);

    return resulting_text;
}

TTF_Font* Hud::loadfont(char* file, int ptsize)
{
    TTF_Font* tmpfont;
    tmpfont = TTF_OpenFont(file, ptsize);
    if (tmpfont == NULL) {
        printf("Unable to load font: %s %s \n", file, TTF_GetError());
    }
    return tmpfont;
}
