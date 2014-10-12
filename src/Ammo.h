#ifndef AMMO_H
#define	AMMO_H

class Ammo {
public:
    Ammo();
    bool Shot();
    int getAmmo();
    void Charge();
    virtual ~Ammo();
private:
    int ammo, frameCount;

};

#endif