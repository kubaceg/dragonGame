#include "World.h"

World::World(SDL_Surface *sc)
{
    screen = sc;
    frameCount = 0;
    clouds = new Clouds(sc);
}

void World::draw()
{
    clouds->draw();
}