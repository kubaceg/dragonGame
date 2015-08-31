#ifndef PROJECT_MENU_H
#define PROJECT_MENU_H


#include "../GameState.h"
#include "FontHelper.h"

class Menu : public FontHelper {
public:
    Menu(SDL_Surface *sc);

    GameState Run();
};


#endif
