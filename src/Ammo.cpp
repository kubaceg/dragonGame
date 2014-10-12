#include "Ammo.h"

Ammo::Ammo() {
    ammo = 100;
    frameCount = 0;
}

Ammo::~Ammo() {
}

bool Ammo::Shot() {
    if(ammo > 0){
        ammo = ammo - 5;
        return true;
    }
    return false;
}

int Ammo::getAmmo() {
    return ammo;
}

void Ammo::Charge() {
    frameCount++;
    if (frameCount == 100) {
        if(ammo != 100) {
            ammo = ammo + 5;
        }
        frameCount = 0;
    }
}