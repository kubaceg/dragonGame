#include <cstdlib>

#include "Game.h"
#include "Hud/Menu.h"
#include "GameState.h"
#include <SDL.h>

using namespace std;

const int WINDOW_WIDTH = 640;
const int WINDOW_HEIGHT = 480;
const char *WINDOW_TITLE = "Dragon";
SDL_Surface *screen;
Game *game;
Menu *menu;
GameState state;

int main(int argc, char **argv) {
    if (SDL_Init(SDL_INIT_EVERYTHING) == -1) {
        return false;
    }

    if (TTF_Init() == -1) {
        return false;
    }
    SDL_Init(SDL_INIT_VIDEO);

    screen = SDL_SetVideoMode(WINDOW_WIDTH, WINDOW_HEIGHT, 0, SDL_HWSURFACE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption(WINDOW_TITLE, 0);
    state = GameState::menu;
    menu = new Menu(screen);

    while (state != GameState::exit) {
        switch (state) {
            case GameState::menu:
                state = menu->Run();
                break;
            case GameState::new_game:
                game = new Game(screen);
                state = game->Run();
                break;
        }
    }

    SDL_Quit();
}
