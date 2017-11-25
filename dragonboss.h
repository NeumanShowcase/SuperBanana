#ifndef DRAGONBOSS_H
#define DRAGONBOSS_H
#include "player.h"
#include "fireball.h"

class dragonBoss : public Player
{
public:
    dragonBoss();
    dragonBoss(int Xpos, int Ypos);
    void paintFire(QPainter* paintMeFromHere);
    void spitFire(int direction);
    bool hitByFireBall(Player* playerToCheck);
    void moveThisObjectLeft(void);
private:
    vector <fireball*> myFireballArr;
};

#endif // DRAGONBOSS_H
