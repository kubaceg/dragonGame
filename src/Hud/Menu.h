#ifndef PROJECT_MENU_H
#define PROJECT_MENU_H


#include "../GameState.h"
#include "../Lib/FontHelper.h"
#include "../Lib/Loop.h"
#include <string>
#include <vector>

class Menu : public FontHelper, public Loop {
private:
    vector <string> positions = {"New game", "Quit"};
    bool bKeyUP, bKeyDOWN, bKeyENTER, bKeyESCAPE;

    void drawPosition(string text, int i);

    void handleEvent();

    GameState state;

    void getSelectedState();

public:
    int selected;

    Menu(SDL_Surface *sc);

    void incMenuSelection();

    void decMenuSelection();

    GameState Run();

    Menu();
};


#endif
