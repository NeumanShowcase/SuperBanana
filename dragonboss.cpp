#include "dragonboss.h"
#define DRAGONHEIGHT 256
#define DRAGONWIDTH 256
#define WINDOWBORDERY 720
#define WINDOWBORDERX 1280
#define FIREBALLREACH 600
#define OUTOFFRAME 0
dragonBoss::dragonBoss()
{

}

dragonBoss::dragonBoss(int Xpos, int Ypos)
{
    myPlayerXpos = Xpos;
    myPlayerYpos = Ypos;

    QSize sizeOfDragon;
    sizeOfDragon.setHeight(DRAGONHEIGHT);
    sizeOfDragon.setWidth(DRAGONWIDTH);
    myPlayerPixHeight = DRAGONHEIGHT;
    myPlayerPixWidth = DRAGONWIDTH;

    myAnim.setFileName(":/Resources/images/dragonBoss.gif");
    myAnim.setScaledSize(sizeOfDragon);
    myAnim.start();
}
void dragonBoss::spitFire(int direction)
{
    if (myFireballArr.size() < 1)
    {
    switch (direction)
    {
    case 8:
    {
        myFireballArr.push_back(new fireball(myPlayerXpos,myPlayerYpos,8));
     break;
    }
    case 9:
    {
        myFireballArr.push_back(new fireball(myPlayerXpos,myPlayerYpos,9));
         break;
    }
    case 12:
    {
        myFireballArr.push_back(new fireball(myPlayerXpos,myPlayerYpos,12));
         break;
    }
    case 15:
    {
        myFireballArr.push_back(new fireball(myPlayerXpos,myPlayerYpos,15));
         break;
    }
    case 16:
    {
        myFireballArr.push_back(new fireball(myPlayerXpos,myPlayerYpos,16));
         break;
    }
    case 6:
    {
        myFireballArr.push_back(new fireball(myPlayerXpos,myPlayerYpos,6));
         break;
    }
    }
    }
}
bool dragonBoss::hitByFireBall(Player* playerToCheck)
{
    for (auto fireball : myFireballArr)
    {
        if(fireball->hitObject(playerToCheck))
        {
            return true;
        }
    }
    return false;
}

void dragonBoss::paintFire(QPainter* paintMeFromHere)
{
   for (int i = 0; i < myFireballArr.size(); ++i)
   {
       if(myFireballArr.at(i) != nullptr)
        {
         myFireballArr.at(i)->paintOut(paintMeFromHere);
        if (myFireballArr.at(i)->getYpos() > WINDOWBORDERY || myFireballArr.at(i)->getXpos() < OUTOFFRAME || myFireballArr.at(i)->getXpos() - myPlayerXpos > FIREBALLREACH )
        {
            delete myFireballArr.at(i);
            myFireballArr.at(i) = nullptr;
            myFireballArr.erase(myFireballArr.begin()+i);
            break;
        }


         // moving in direction of switch //
        switch (myFireballArr.at(i)->getDirection())
        {
        case 8:
        {
         myFireballArr.at(i)->moveThisObject(-1,1);
         break;
        }
        case 9:
        {
            myFireballArr.at(i)->moveThisObject(-1,0);
             break;
        }
        case 12:
        {

             myFireballArr.at(i)->moveThisObject(0,-1);
             break;
        }
        case 15:
        {
            myFireballArr.at(i)->moveThisObject(1,0);
             break;
        }
        case 16:
        {
        myFireballArr.at(i)->moveThisObject(1,1);
             break;
        }
        case 6:
        {
            myFireballArr.at(i)->moveThisObject(0,1);
                 break;
        }
        }
         }
    }
}
void dragonBoss::moveThisObjectLeft(void)
{
    --myPlayerXpos;
    for (auto fireball : myFireballArr)
    {
        fireball->moveThisObjectLeft();
    }
}
