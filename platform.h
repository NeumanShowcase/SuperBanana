#ifndef PLATFORM_H
#define PLATFORM_H

#include <QGraphicsItem>
#include "platform.h"
#include "player.h"
#include <QMovie>
#include <QLabel>

class Platform
{
public:
    Platform();

    Platform(QPixmap inputPath,int inputHeight,int inputWidth,float Ypos=0,float Xpos=0);

    bool hitObject(Player* checkthisplayer);

    void paintOut(QPainter* paintMeFromHere);

    QPixmap getFrameFromAnimation(void);

    int getPixmapRight(void);

    int getPixmapTop(void);

    void moveThisObjectLeft(void);

    void moveThisObjectRight(void);

    void moveThisObject(int X =0,int Y =0);

    int getMovedSteps(void);

    void setMovedSteps(int);

    int getXpos(void);

    int getYpos(void);
protected:
    QPixmap myPixmap;
    int myMovedSteps = 0;
    float myPixmapYpos;
    float myPixmapXpos;
    int myPixmapWidth;
    int myPixmapHeight;
    QMovie myAnim;

};

#endif // PLATFORM_H
