#include "Menu.h"

Menu::Menu(SDL_Surface *sc) : FontHelper(sc) {
    screen = sc;
    selected = 0;
}

GameState Menu::Run() {
    SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 60, 60));

    for (int i = 0; i < positions.size(); i++) {
        drawPosition(positions[i], i);
    }

    return GameState::menu;
}

void Menu::drawPosition(string text2, int pos) {
    char *cstr = new char[text2.length() + 1];
    strcpy(cstr, text2.c_str());
    SDL_Surface *text;
    if (selected == pos) {
        color = {255, 50, 100};
    } else {
        color = {0, 100, 255};
    }
    text = drawText(font, color, cstr);
    SDL_Rect p = position;
    p.y = position.y + (40 * pos) + 10;
    SDL_BlitSurface(text, NULL, screen, &p);
    delete[] cstr;
}

void Menu::incMenuSelection() {
    if (selected < positions.size()-1) {
        selected++;
    }
}

void Menu::decMenuSelection() {
    if (selected > 0) {
        selected--;
    }
}