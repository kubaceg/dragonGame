#include "Hud.h"

Hud::Hud(SDL_Surface *sc) : FontHelper(sc)
{
    screen = sc;
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

void Hud::drawAmmoBar(int ammo)
{
    int screenWidth = 640;
    rectangleRGBA(screen, screenWidth-151, 10, screenWidth-49, 30, 255, 255, 255, 255);
    boxRGBA(screen, screenWidth-150, 11, screenWidth-150+ammo, 29, 255, 0, 0, 255);
}
