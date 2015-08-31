#include "Menu.h"

Menu::Menu(SDL_Surface *sc) : FontHelper(sc){
    screen = sc;
}

GameState Menu::Run() {
    SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 60, 60));
    char str[8];
    sprintf(str, "%s", "New game");
    SDL_Surface *text;
    text = drawtext(font, color, str);

    SDL_BlitSurface(text, NULL, screen, &position);

    return GameState::menu;
}