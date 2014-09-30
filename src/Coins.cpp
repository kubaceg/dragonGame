#include "Coins.h"

Coins::Coins(SDL_Surface *sc)
{
    screen = sc;
    position = 0;
    frameCount = 0;
    level = 5;


    coin[0] = IMG_Load("graph/coin/goldCoin1.png");
    coin[1] = IMG_Load("graph/coin/goldCoin2.png");
    coin[2] = IMG_Load("graph/coin/goldCoin3.png");
    coin[3] = IMG_Load("graph/coin/goldCoin4.png");
    coin[4] = IMG_Load("graph/coin/goldCoin5.png");
    coin[5] = IMG_Load("graph/coin/goldCoin6.png");
    coin[6] = IMG_Load("graph/coin/goldCoin7.png");
    coin[7] = IMG_Load("graph/coin/goldCoin8.png");
    coin[8] = IMG_Load("graph/coin/goldCoin9.png");
}

void Coins::draw()
{
    frameCount++;
    if (frameCount == 10)
    {
        position++;
        if (position == 9) position = 0;
        frameCount = 0;
        level--;
    }
    
    generateCoin();

    for (list<SDL_Rect>::iterator iter = coinsPosition.begin(); iter != coinsPosition.end(); iter++)
    {
        (*iter).x++;
        SDL_BlitSurface(coin[position], NULL, screen, &(*iter));
    }
}

void Coins::generateCoin()
{
    if(level == 0) 
    {
        SDL_Rect coinPos;
        coinPos.x = 0;
        coinPos.y = generateCoinYPosition();
        coinPos.w = 32;
        coinPos.h = 32;
        coinsPosition.push_back(coinPos);
        level = std::rand() % 20;
    }
}

int Coins::generateCoinYPosition()
{
    return std::rand() % screen->h;
}

int Coins::detectColision(list<SDL_Rect> *flames)
{
    points = 0;

    for ( list<SDL_Rect >::iterator flame = (*flames).begin(); flame != (*flames).end(); flame++ )
    {
        flameX = (*flame).x;
        flameYmin = (*flame).y;
        flameY = (*flame).y + ((*flame).h * 0.5);

        for ( list<SDL_Rect >::iterator coin = coinsPosition.begin(); coin != coinsPosition.end(); coin++ )
        {
            if(flameX == (*coin).x+(*coin).w) {
                if((*coin).y < flameY && ((*coin).y+(*coin).h) > flameY){
                    coin = coinsPosition.erase(coin);
                    flame = (*flames).erase(flame);
                    points++;
                }
            }
        }
    }

    return points;
}
