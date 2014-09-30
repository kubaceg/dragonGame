#include "Dragon.h"
#include "World.h"
#include "Coins.h"
#include "Flames.h"
#include "Hud.h"

const int WINDOW_WIDTH = 640;
const int WINDOW_HEIGHT = 480;
const char *WINDOW_TITLE = "Dragon";

Dragon *dr = NULL;
World *wr = NULL;
Coins *co = NULL;
Flames * fl = NULL;
Hud *hd = NULL;

int FPS = 60;
int NextTick , interval ;
void FPS_Initial(void)
{
    NextTick = 0 ;
    interval = 1 * 1000 / FPS ;
    return;
}

void FPS_Fn(void)
{
    if ( NextTick > SDL_GetTicks( ) ) SDL_Delay( NextTick - SDL_GetTicks( ) );
    NextTick = SDL_GetTicks( ) + interval ;
    return;
}

int main(int argc, char **argv)
{
    if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
           {
                   return false;    
               }

     if( TTF_Init() == -1 )
            {
                    return false;    
                }
    SDL_Init( SDL_INIT_VIDEO );

    SDL_Surface *screen = SDL_SetVideoMode( WINDOW_WIDTH, WINDOW_HEIGHT, 0,
                                            SDL_HWSURFACE | SDL_DOUBLEBUF );
    SDL_WM_SetCaption( WINDOW_TITLE, 0 );

    dr = new Dragon(screen);
    wr = new World(screen);
    co = new Coins(screen);
    fl = new Flames(screen);
    hd = new Hud(screen);


    SDL_Event event;
    bool gameRunning = true;
    bool bKeyUP = 0 , bKeyDOWN = 0 , bKeyLEFT = 0 , bKeyRIGHT = 0;
    int pidx = 0 , aTick = 0, points = 0;

    SDL_Rect destination;
    destination.x = 500;
    destination.y = 100;
    destination.w = 65;
    destination.h = 44;

    FPS_Initial( );

    while (gameRunning)
    {
        aTick++;

        SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 138, 255));
        wr->draw();
        dr->move(destination);

        fl->draw();

        co->draw();  
        points += co->detectColision(fl->getFlamePositions());
        hd->draw(points);

        SDL_Flip(screen);

        FPS_Fn();
        if (SDL_PollEvent(&event))
        {

            SDLKey keyPressed = event.key.keysym.sym;

            switch (event.type)
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
                    fl->shot(destination);
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
        if (bKeyUP) destination.y = destination.y - 1;
        if (bKeyDOWN) destination.y = destination.y + 1;
        if (bKeyLEFT) destination.x = destination.x - 1;
        if (bKeyRIGHT) destination.x = destination.x + 1;
    }
    SDL_Quit();

    return 0;
}
