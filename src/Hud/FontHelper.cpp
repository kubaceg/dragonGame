#include "FontHelper.h"

FontHelper::FontHelper(SDL_Surface *sc) {
    screen = sc;
    font = loadfont("graph/font.ttf", 40);
    color = {255, 50, 100};
    position = {10, 10};
}

SDL_Surface *FontHelper::drawtext(TTF_Font *font, SDL_Color color, char text[]) {
    SDL_Surface *resulting_text;

    resulting_text = TTF_RenderText_Solid(font, text, color);

    return resulting_text;
}


TTF_Font *FontHelper::loadfont(char *file, int ptsize) {
    TTF_Font *tmpfont;
    tmpfont = TTF_OpenFont(file, ptsize);
    if (tmpfont == NULL) {
        printf("Unable to load font: %s %s \n", file, TTF_GetError());
    }
    return tmpfont;
}