#include "World.h"

World::World(SDL_Surface *sc)
{
    screen = sc;
    frameCount = 0;

    destination[0].x = 0;
    destination[0].y = 50;
    destination[0].w = 64;
    destination[0].h = 32;

    destination[1].x = 50;
    destination[1].y = 100;
    destination[1].w = 64;
    destination[1].h = 32;

    destination[2].x = 50;
    destination[2].y = 150;
    destination[2].w = 64;
    destination[2].h = 32;

    destination[3].x = 200;
    destination[3].y = 250;
    destination[3].w = 64;
    destination[3].h = 32;

    for (int i = 0; i < 4; i++)
    {
        cloud[i] = SDL_LoadBMP("graph/cloud.bmp");
        SDL_SetColorKey( cloud[i], SDL_SRCCOLORKEY, SDL_MapRGB(cloud[i]->format, 255, 0, 255) );
    }
}

void World::draw()
{
    if (frameCount == 5)
    {
    	for (int i = 0; i < 4; i++) {
        	destination[i].x++;
        }
        frameCount = 0;
    }
    
    for (int i = 0; i < 4; i++)
    {
        SDL_BlitSurface(cloud[i], NULL, screen, &destination[i]);
    }
    frameCount++;
}