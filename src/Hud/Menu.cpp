#include "Menu.h"

Menu::Menu(SDL_Surface *sc) : FontHelper(sc) {
    screen = sc;
    selected = 0;
    FPS = 30;
    position = {30, 30};
}

GameState Menu::Run() {
    FPS_Initial();
    running = true;
    bKeyUP = bKeyDOWN = bKeyENTER = bKeyESCAPE = false;
    state = GameState::menu;

    while (running) {
        aTick++;

        handleEvent();
        SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 60, 60));
        for (int i = 0; i < positions.size(); i++) {
            drawPosition(positions[i], i);
        }

        FPS_Fn();
        SDL_Flip(screen);
    }

    return state;
}

void Menu::drawPosition(string text2, int pos) {
    char *cstr = new char[text2.length() + 1];
    int textW, textH;
    strcpy(cstr, text2.c_str());
    SDL_Surface *text;
    if (selected == pos) {
        color = {255, 50, 100};
    } else {
        color = {0, 100, 255};
    }
    text = drawText(font, color, cstr);
    TTF_SizeText(font, cstr, &textW, &textH);
    SDL_Rect p = position;
    p.y = position.y + (40 * pos) + 10;
    p.x = 320 - (textW / 2);
    SDL_BlitSurface(text, NULL, screen, &p);
    delete[] cstr;
}

void Menu::incMenuSelection() {
    if (selected < positions.size() - 1) {
        selected++;
    }
}

void Menu::decMenuSelection() {
    if (selected > 0) {
        selected--;
    }
}

void Menu::handleEvent() {
    SDL_Event event;

    if (SDL_PollEvent(&event)) {
        SDLKey keyPressed = event.key.keysym.sym;

        switch (event.type) {
            case SDL_KEYDOWN:
                switch (keyPressed) {
                    case SDLK_UP:
                        bKeyUP = 1;
                        break;
                    case SDLK_DOWN:
                        bKeyDOWN = 1;
                        break;
                    case SDLK_ESCAPE:
                        bKeyESCAPE = 1;
                        break;
                    case SDLK_RETURN:
                        bKeyENTER = 1;
                        break;
                }
                break;
            case SDL_KEYUP:
                switch (keyPressed) {
                    case SDLK_UP:
                        bKeyUP = 0;
                        break;
                    case SDLK_DOWN:
                        bKeyDOWN = 0;
                        break;
                    case SDLK_RETURN:
                        bKeyENTER = 0;
                        break;
                    case SDLK_ESCAPE:
                        bKeyESCAPE = 0;
                        break;
                }
                break;
            case SDL_QUIT:
                running = false;
                state = GameState::exit;
                break;
        }

        if (bKeyUP) decMenuSelection();
        if (bKeyDOWN) incMenuSelection();
        if (bKeyENTER) {
            running = false;
            getSelectedState();
        }
    }
}

void Menu::getSelectedState() {
    switch (selected) {
        case 0:
            state = GameState::new_game;
            break;
        case 1:
            state = GameState::exit;
            break;
    }
}
