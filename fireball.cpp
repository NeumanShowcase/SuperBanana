#include "fireball.h"
#define FIREBALLHEIGHT 100
#define FIREBALLWIDTH 130
fireball::fireball()
{

}

fireball::fireball(int Xpos, int Ypos, int direction)
{
    myDirection = direction;
    QSize sizeOfFireball;
    sizeOfFireball.setHeight(FIREBALLHEIGHT);
    sizeOfFireball.setWidth(FIREBALLWIDTH);
    myPixmapHeight = FIREBALLHEIGHT;
    myPixmapWidth = FIREBALLWIDTH;
    myPixmapXpos = Xpos;
    myPixmapYpos = Ypos;
    myAnim.setFileName(":/Resources/images/fireball.gif");
    myAnim.setScaledSize(sizeOfFireball);
    myAnim.start();
    //myPixmap = myAnim.currentPixmap();
}
 int fireball::getDirection (void)
{
     return myDirection;
}

