#include "flooring.h"

flooring::flooring()

{

}

flooring::flooring(int Xpos, int Ypos)
{
myPixmap.load(":/Resources/images/background_texture1.jpg");
myPixmapXpos = Xpos;
myPixmapYpos = Ypos;
myPixmapHeight = myPixmap.height();
myPixmapWidth = myPixmap.width();
}
