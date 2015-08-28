#include "Clouds.h"

Clouds::Clouds(SDL_Surface *sc) {
    std::srand(time(0));
    screen = sc;
    frameCount = 0;
    level = 0;

    bitmap = IMG_Load("graph/clouds.png");

    cloudVersionImage[0].x = 0;
    cloudVersionImage[0].y = 0;
    cloudVersionImage[0].w = 150;
    cloudVersionImage[0].h = 70;

    cloudVersionImage[1].x = 18;
    cloudVersionImage[1].y = 76;
    cloudVersionImage[1].w = 102;
    cloudVersionImage[1].h = 48;

    cloudVersionImage[2].x = 18;
    cloudVersionImage[2].y = 130;
    cloudVersionImage[2].w = 113;
    cloudVersionImage[2].h = 47;

    cloudVersionImage[3].x = 24;
    cloudVersionImage[3].y = 182;
    cloudVersionImage[3].w = 98;
    cloudVersionImage[3].h = 46;

    generate(100);
    generate(0);
    generate(500);
}

void Clouds::draw() {
    int i = 0;
    for (list<SDL_Rect>::iterator iter = clouds.begin(); iter != clouds.end(); iter++) {
        SDL_BlitSurface(bitmap, &cloudVersionImage[cloudVersion[i]], screen, &(*iter));
        i++;
    }
}

void Clouds::generate(int x = 0) {
    if (level == 0) {
        SDL_Rect cloud;
        cloud.x = x;
        cloud.y = generateYPosition();
        int version = generateVersion();
        cout << version << endl;

        cloud.w = cloudVersionImage[version].w;
        cloud.h = cloudVersionImage[version].h;
        clouds.push_back(cloud);
        cloudVersion.push_back(version);
    }
}

int Clouds::generateYPosition() {
    return std::rand() % screen->h;
}

int Clouds::generateVersion() {
    return std::rand() % 3;
}