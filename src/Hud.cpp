#include "Hud.h"

Hud::Hud(SDL_Surface *sc)
{
    screen = sc;
    font = loadfont("/home/kuba/.fonts/Allura-Regular.ttf", 24);
    color = {255, 255, 255};
}

void Hud::draw(int points)
{
   SDL_Surface *text;
   char *str;
SDL_Rect offset;

    offset.x = 10;
        offset.y = 10;
   sprintf(str, "%d", points);
   SDL_Color textColor = { 255, 255, 255 };

   text = TTF_RenderText_Solid(font, "super", textColor); 
   SDL_BlitSurface(text, NULL, screen, &offset);
}

  TTF_Font* Hud::loadfont(char* file, int ptsize)
      {
          TTF_Font* tmpfont;
          tmpfont = TTF_OpenFont(file, (char)ptsize);
          if (tmpfont == NULL){
                printf("Unable to load font: %s %s \n", file, TTF_GetError());
                     }
                         return tmpfont;
                       }
