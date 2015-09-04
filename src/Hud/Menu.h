#ifndef PROJECT_MENU_H
#define PROJECT_MENU_H


#include "../GameState.h"
#include "FontHelper.h"
#include <string>
#include <vector>

class Menu : public FontHelper {
private:
    vector<string> positions = {"New game", "Quit"};
    void drawPosition(string text, int i);
public:
    int selected;
    Menu(SDL_Surface *sc);
    void incMenuSelection();
    void decMenuSelection();
    GameState Run();
};


#endif
