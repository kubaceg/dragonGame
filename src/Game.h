#ifndef GAME_H
#define    GAME_H

#include "Dragon.h"
#include "World.h"
#include "Coins.h"
#include "Flames.h"
#include "Hud/Hud.h"
#include "Hud/Menu.h"
#include "Ammo.h"
#include "GameState.h"

class Game {
private:
    void FPS_Initial(void);

    void FPS_Fn(void);

    void handleEvent();

    void gameMainLoop();

    bool Init(void);

    bool gameRunning, bKeyUP, bKeyDOWN, bKeyLEFT, bKeyRIGHT, bKeyENTER, bKeyESCAPE;
    SDL_Event *event;
    SDL_Rect *dragonPosition;
    Dragon *dr;
    World *wr;
    Coins *co;
    Flames *fl;
    Hud *hd;
    Ammo *ammo;
    Menu *menu;
    int NextTick, interval, pidx, aTick, points;
    GameState currentGameState;


public:
    const int WINDOW_WIDTH = 640;
    const int WINDOW_HEIGHT = 480;
    const int FPS = 60;
    const char *WINDOW_TITLE = "Dragon";
    SDL_Surface *screen;

    void Run(void);

    Game(SDL_Surface* sc);
};

#endif

