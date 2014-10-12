#include "Hud.h"

Hud::Hud(SDL_Surface *sc)
{
    screen = sc;
    font = loadfont("graph/font.ttf", 40);
    color = {255, 50, 100};
    position = {10,10};
}

void Hud::draw(int points, int ammo)
{
    drawPoints(points);
    drawAmmoBar(ammo);
}

void Hud::drawPoints(int points) 
{
    char str[5];
    sprintf(str, "%d", points);
    SDL_Surface* text;
    text = drawtext(font, color, str);

    SDL_BlitSurface(text, NULL, screen, &position);
}

SDL_Surface* Hud::drawtext(TTF_Font* font, SDL_Color color, char text[])
{
    SDL_Surface* resulting_text;

    resulting_text = TTF_RenderText_Solid(font, text, color);

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

void Hud::drawAmmoBar(int ammo)
{
    int screenWidth = 640;
    rectangleRGBA(screen, screenWidth-151, 10, screenWidth-49, 30, 255, 255, 255, 255);
    boxRGBA(screen, screenWidth-150, 11, screenWidth-150+ammo, 29, 255, 0, 0, 255);
}
