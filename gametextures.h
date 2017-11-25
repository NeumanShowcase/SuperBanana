#ifndef GAMETEXTURES_H
#define GAMETEXTURES_H
#include "flooring.h"
#include "player.h"
#include "pickupitem.h"
#include <QPainter>
#include "dragonboss.h"
#include <QPixmap>
//class dragonBoss;
//#include <windows.h>
#define SPEEDOFWORLD 1.5
#define DISTANCETOSTARTMOVEWORLD 500
#define RESOLUTION 720

class GameTextures
{
public:
    GameTextures();
    void paintFloor(QPainter* qp);
    // **remake this to work with vector instead** //
    int collisionCheck(Player* playerToCheck);
    // this will add floorpixmap on the desired position x and y if call empty: create tile after last one on platform //

    void addFloorHere(int Xpos = 0,int Ypos = 0);

    void addPickup(int Xpos = 0,int Ypos = 0,int typeOfPickup = 0,int howMany = 1);

    void paintCoin(QPainter* qp);

    void moveWorld(void);

    void paintWindowBorders(QPainter* qp);

    void timeToMoveObjects(Player* inputtedPlayer);

    void clearLevel(void);

    void reWindToStart(void);

    void spawnDragonboss(int Xpos, int Ypos);

    void paintDragonboss(QPainter* paintFromHere);


private:
    std::vector<flooring*>myFloorArr;
    std::vector<pickupItem*>myPickablesArr;
    QRect myWindowBorder;
    dragonBoss* myDragonboss;
    QPixmap myBackground;

};

#endif // GAMETEXTURES_H
