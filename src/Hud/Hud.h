#ifndef __HUD_H__
#define __HUD_H__

#include "FontHelper.h"

class Hud : public FontHelper
{
private:
    void drawPoints(int points);
    void drawAmmoBar(int ammo);

public:
    void draw(int points, int ammo);
    Hud(SDL_Surface* sc);
};
#endif
