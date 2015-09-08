#ifndef GAME_H
#define    GAME_H

#include "Dragon.h"
#include "World.h"
#include "Coins.h"
#include "Flames.h"
#include "Hud/Hud.h"
#include "Hud/Menu.h"
#include "Lib/Loop.h"
#include "Ammo.h"
#include "GameState.h"

class Game : public Loop {
private:
    void handleEvent();

    void gameMainLoop();

    bool Init(void);

    bool bKeyUP, bKeyDOWN, bKeyLEFT, bKeyRIGHT, bKeyENTER, bKeyESCAPE;
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
    SDL_Surface *screen;

    GameState Run(void);

    Game(SDL_Surface *sc);
};

#endif

