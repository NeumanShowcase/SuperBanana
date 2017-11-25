#ifndef FIREBALL_H
#define FIREBALL_H
#include "platform.h"

class fireball: public Platform
{
public:
    fireball();
    fireball(int Xpos, int Ypos, int direction);
    int getDirection (void);
//    bool hitObject(Player* checkthisplayer);
private:
    int myDirection = 0;
};

#endif // FIREBALL_H
