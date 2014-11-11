#ifndef GAMEOBJECT_HPP
#define	GAMEOBJECT_HPP
#include "SDL.h"
#include "SDL/SDL_image.h"
#include <cstdlib>

using namespace std;

class GameObject {
public:
    GameObject(SDL_Surface* sc);
    virtual ~GameObject();
    void draw();
    bool move();
    
protected:
    int generateYPosition();
    SDL_Surface* screen;
    SDL_Rect dimensions;
};

#endif

