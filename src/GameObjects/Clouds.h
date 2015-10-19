#ifndef PROJECT_CLOUDS_H
#define PROJECT_CLOUDS_H
#include "SDL.h"
#include "SDL/SDL_image.h"
#include <list>
#include <cstdlib>
#include <vector>
#include <iostream>
using namespace std;

class Clouds {
private:
    list<SDL_Rect> clouds;
    vector<int> cloudVersion;
    SDL_Rect cloudVersionImage[4];
    SDL_Surface* screen;
    SDL_Surface* bitmap;
    int frameCount, level;
    void generate(int x = 0);
    int generateYPosition(int cloudHeight);
    int generateVersion();

public:
    void draw();
    Clouds(SDL_Surface* sc);
};
#endif