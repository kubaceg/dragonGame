#include "Flames.h"

Flames::Flames(SDL_Surface *sc)
{
    screen = sc;
    position = 0;
    frameCount = 0;

    flame = IMG_Load("graph/flame.png");
}

void Flames::draw()
{
    frameCount++;

    for ( list<SDL_Rect >::iterator iter = flames.begin(); iter != flames.end(); iter++ )
    {
        if ((*iter).w != 0)
            SDL_BlitSurface(flame, NULL, screen, &(*iter));

        (*iter).x--;
        if ((*iter).x == 0) iter = flames.erase(iter);
    }
}

void Flames::shot(SDL_Rect dragonPosition)
{
    if(frameCount > 10) {
        flamePosition.x = dragonPosition.x - 16;
        flamePosition.y = dragonPosition.y + 26;
        flamePosition.w = 16;
        flamePosition.h = 12;

        flames.push_back(flamePosition);
        frameCount = 0;
    }
}

list<SDL_Rect>* Flames::getFlamePositions()
{
    return &flames;  
}
