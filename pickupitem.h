#ifndef PICKUPITEM_H
#define PICKUPITEM_H
#include "platform.h"
#include <QMovie>
#define COINHEIGHT 23
#define COINWIDTH 18
class pickupItem: public Platform
{
public:
    pickupItem();
    pickupItem(int Xpos, int Ypos, int type);
    string getType(void);
private:
    string myType = "none";
};

#endif // PICKUPITEM_H
