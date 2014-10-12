#include "Game.h"

Game::Game() {
    Init();
}

bool Game::Init() {
    if (SDL_Init(SDL_INIT_EVERYTHING) == -1) {
        return false;
    }

    if (TTF_Init() == -1) {
        return false;
    }
    SDL_Init(SDL_INIT_VIDEO);

    screen = SDL_SetVideoMode(WINDOW_WIDTH, WINDOW_HEIGHT, 0, SDL_HWSURFACE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption(WINDOW_TITLE, 0);
    
    points = pidx = aTick = 0;
    bKeyUP = bKeyDOWN = bKeyLEFT = bKeyRIGHT = false;
    
    //Init Game objects 
    dr = new Dragon(screen);
    wr = new World(screen);
    co = new Coins(screen);
    fl = new Flames(screen);
    hd = new Hud(screen);
    
    dragonPosition = new SDL_Rect();
    dragonPosition->x = 500;
    dragonPosition->y = 100;
    dragonPosition->w = 65;
    dragonPosition->h = 44;
}

void Game::Run() {
    FPS_Initial( );

    gameRunning = true;
    while (gameRunning)
    {
        aTick++;
        handleEvent();
        SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 138, 255));
        wr->draw();
        dr->move(dragonPosition);

        fl->draw();

        co->draw();  
        points += co->detectColision(fl->getFlamePositions());
        hd->draw(points);

        SDL_Flip(screen);

        FPS_Fn();
    }
    SDL_Quit();
}

void Game::FPS_Initial()
{
    NextTick = 0 ;
    interval = 1 * 1000 / FPS ;
    return;
}

void Game::FPS_Fn() {
    if (NextTick > SDL_GetTicks()) SDL_Delay(NextTick - SDL_GetTicks());
    NextTick = SDL_GetTicks() + interval;
    return;
}

void Game::handleEvent() {
        if (SDL_PollEvent(event))
        {
            SDLKey keyPressed = event->key.keysym.sym;
 
            switch (event->type)
            {
            case SDL_KEYDOWN:
                switch ( keyPressed )
                {
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
                    gameRunning = false;
                    break;
                case SDLK_SPACE:
                    fl->shot(dragonPosition);
                    break;
                }
                break;
            case SDL_KEYUP:
                switch ( keyPressed )
                {
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
                default:
                    break;
                }
                break;
            case SDL_QUIT:
                gameRunning = false;
                break;
            }

        }
        if (bKeyUP) dragonPosition->y = dragonPosition->y - 1;
        if (bKeyDOWN) dragonPosition->y = dragonPosition->y + 1;
        if (bKeyLEFT) dragonPosition->x = dragonPosition->x - 1;
        if (bKeyRIGHT) dragonPosition->x = dragonPosition->x + 1;
}
