#include "World.h"

World::World(SDL_Surface *sc) {
    screen = sc;
    frameCount = 0;
    background = IMG_Load("graph/cloudsbg.png");

    bgPosition.x = 0;
    bgPosition.y = 0;
    bgPosition.w = 640;
    bgPosition.h = 480;
}

void World::draw() {
    frameCount++;

    if (frameCount == 10) {
        bgPosition.x += 1;
        frameCount = 0;
    }

    SDL_BlitSurface(background, &bgPosition, screen, NULL);
}