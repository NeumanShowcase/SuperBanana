#include "platform.h"
#define DISTANCETOCOLLIDE 10
Platform::Platform()
{
}

void Platform::paintOut(QPainter * paintMeFromHere)
{   if(myAnim.isValid())
    {
        paintMeFromHere->drawPixmap(myPixmapXpos,myPixmapYpos,myAnim.currentPixmap());
    }
    else

        paintMeFromHere->drawPixmap(myPixmapXpos,myPixmapYpos,myPixmap);
}
 Platform::Platform(QPixmap inputPath,int inputHeight,int inputWidth,float Ypos,float Xpos)
 {
      myPixmap = inputPath;
      myPixmapHeight = inputHeight;
      myPixmapWidth = inputWidth;
      myPixmapXpos = Xpos;
      myPixmapYpos = Ypos;
 }
bool Platform::hitObject(Player *checkthisplayer)
{



    QPoint returnedPlayerCenter = checkthisplayer->getPlayerCenter();
    float resultingDistance = sqrt((pow(returnedPlayerCenter.x()-(myPixmapXpos+myPixmapWidth/2),2) + (pow(returnedPlayerCenter.y()-(myPixmapYpos+myPixmapHeight/2),2) )));
    if (resultingDistance < DISTANCETOCOLLIDE)
    {
        return true;
    }

    if (checkthisplayer->getPlayerShoes() == myPixmapYpos && (checkthisplayer->getPlayerRight() >=myPixmapXpos) )
    {
        if (checkthisplayer->getPlayerLeft() <= myPixmapXpos+myPixmapWidth)
        {
           //qDebug("COLLISION!!!!!");
            return true;
        }
    }

    return false;
}
int Platform::getPixmapRight(void)
{
    return this->myPixmapXpos + this->myPixmapWidth;
}
int Platform::getPixmapTop(void)
{
return myPixmapYpos;
}
QPixmap Platform::getFrameFromAnimation(void)
{
    return myAnim.currentPixmap();
}
void Platform::moveThisObjectLeft(void)
{
   --myPixmapXpos;
   ++myMovedSteps;
}
void Platform::moveThisObjectRight(void)
{
    ++myPixmapXpos;
}
int Platform::getMovedSteps(void)
{
    return myMovedSteps;
}
void Platform::setMovedSteps(int inputnumber)
{
    myMovedSteps = inputnumber;
}
void Platform::moveThisObject(int X,int Y)
{
    myPixmapXpos +=X;
    myPixmapYpos +=Y;
}
int Platform::getXpos(void)
{
    return myPixmapXpos;
}
int Platform::getYpos(void)
{
    return myPixmapYpos;
}
