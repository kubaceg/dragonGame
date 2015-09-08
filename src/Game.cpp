#include "Game.h"

Game::Game(SDL_Surface *sc) {
    screen = sc;
    Init();
}

bool Game::Init() {
    points = pidx = aTick = 0;
    bKeyUP = bKeyDOWN = bKeyLEFT = bKeyRIGHT = bKeyENTER = bKeyESCAPE = false;

    //Init Game objects 
    dr = new Dragon(screen);
    wr = new World(screen);
    co = new Coins(screen);
    fl = new Flames(screen);
    hd = new Hud(screen);
    ammo = new Ammo();

    dragonPosition = new SDL_Rect();
    dragonPosition->x = 500;
    dragonPosition->y = 100;
    dragonPosition->w = 65;
    dragonPosition->h = 44;
}

GameState Game::Run() {
    FPS_Initial();
    running = true;
    while (running) {
        aTick++;
        handleEvent();
        gameMainLoop();
        FPS_Fn();
        SDL_Flip(screen);
    }

    return currentGameState;
}

void Game::gameMainLoop() {
    SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 138, 255));
    ammo->Charge();
    wr->draw();
    dr->move(dragonPosition);
    fl->draw();
    co->draw();
    points += co->detectColision(fl->getFlamePositions());
    hd->draw(points, ammo->getAmmo());
}

void Game::handleEvent() {
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
                    case SDLK_LEFT:
                        bKeyLEFT = 1;
                        break;
                    case SDLK_RIGHT:
                        bKeyRIGHT = 1;
                        break;
                    case SDLK_ESCAPE:
                        bKeyESCAPE = 1;
                        break;
                    case SDLK_RETURN:
                        bKeyENTER = 1;
                        break;
                    case SDLK_SPACE:
                        if (ammo->Shot()) {
                            fl->shot(dragonPosition);
                        }
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
                    case SDLK_LEFT:
                        bKeyLEFT = 0;
                        break;
                    case SDLK_RIGHT:
                        bKeyRIGHT = 0;
                        break;
                    case SDLK_RETURN:
                        bKeyENTER = 0;
                        break;
                    case SDLK_ESCAPE:
                        bKeyESCAPE = 0;
                        break;
                    default:
                        break;
                }
                break;
            case SDL_QUIT:
                running = false;
                break;
        }

    }
    else {
        if (bKeyUP) dragonPosition->y = dragonPosition->y - 1;
        if (bKeyDOWN) dragonPosition->y = dragonPosition->y + 1;
        if (bKeyLEFT) dragonPosition->x = dragonPosition->x - 1;
        if (bKeyRIGHT) dragonPosition->x = dragonPosition->x + 1;
        if (bKeyESCAPE) {
            currentGameState = GameState::menu;
            running = false;
        }
    }
}
