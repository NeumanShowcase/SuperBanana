#ifndef FLOORING_H
#define FLOORING_H
#include "platform.h"

class flooring: public Platform
{
public:

    flooring();
    // making new floor on this position with this height and width //
    flooring(int Xpos, int Ypos);

};

#endif // FLOORING_H
