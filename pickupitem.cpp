#include "pickupitem.h"

pickupItem::pickupItem()
{

}


pickupItem::pickupItem(int Xpos, int Ypos,int type)
{
if (type == 0)
{
myType = "coin";
QSize sizeOfCoin;
sizeOfCoin.setHeight(COINHEIGHT);
sizeOfCoin.setWidth(COINWIDTH);
myPixmapHeight = COINHEIGHT;
myPixmapWidth = COINWIDTH;

myAnim.setFileName(":/Resources/images/quarterAnim.gif");
myAnim.setScaledSize(sizeOfCoin);
myAnim.start();
//myPixmap = myAnim.currentPixmap();

}
if (type == 1)
{
myType = "endGameButton";
QSize sizeOfGameover;
sizeOfGameover.setHeight(COINHEIGHT+100);
sizeOfGameover.setWidth(COINWIDTH+100);
myPixmapHeight = COINHEIGHT+100;
myPixmapWidth = COINWIDTH+100;

myAnim.setFileName(":/Resources/images/quarterAnim.gif");
myAnim.setScaledSize(sizeOfGameover);
myAnim.start();
//myPixmap = myAnim.currentPixmap();

}

myPixmapXpos = Xpos;
myPixmapYpos = Ypos;


}



string pickupItem::getType(void)
{
    return myType;
}
