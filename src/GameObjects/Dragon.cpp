#include "Dragon.h"

Dragon::Dragon(SDL_Surface *sc)
{
    screen = sc;
    position = 0;
    frameCount = 0;

    destination.x = 200;
    destination.y = 100;
    destination.w = 65;
    destination.h = 44;

    dragon[0].x = 24;
    dragon[0].y = 64;
    dragon[0].w = 66;
    dragon[0].h = 52;

    dragon[1].x = 156;
    dragon[1].y = 64;
    dragon[1].w = 66;
    dragon[1].h = 52;

    dragon[2].x = 288;
    dragon[2].y = 64;
    dragon[2].w = 66;
    dragon[2].h = 52;

    dragon[3].x = 420;
    dragon[3].y = 64;
    dragon[3].w = 66;
    dragon[3].h = 52;

    dragon[4].x = 24;
    dragon[4].y = 194;
    dragon[4].w = 66;
    dragon[4].h = 52;

    dragon[5].x = 156;
    dragon[5].y = 194;
    dragon[5].w = 66;
    dragon[5].h = 52;

    dragon[6].x = 288;
    dragon[6].y = 194;
    dragon[6].w = 66;
    dragon[6].h = 52;

    bitmap = SDL_LoadBMP("graph/bat.bmp");
    SDL_SetColorKey( bitmap, SDL_SRCCOLORKEY, SDL_MapRGB(bitmap->format, 255, 0, 255) );
}

void Dragon::draw()
{
    if (frameCount == 5)
    {
        position++;
        if (position == 7)
            position = 0;

        frameCount = 0;
    }

    SDL_BlitSurface(bitmap, &dragon[position], screen, &destination);
    frameCount++;
}

void Dragon::move(SDL_Rect *pos){
    destination.x = pos->x;
    destination.y = pos->y;
    draw();
}