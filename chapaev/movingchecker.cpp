#include "movingchecker.h"

MovingChecker::MovingChecker(Checker *c)
{
    this->checker = c;
    this->Xspeed = 0;
    this->Yspeed = 0;
}

MovingChecker::MovingChecker(Checker *c, float Xspeed, float Yspeed)
{
    this->checker = c;
    this->Xspeed = Xspeed;
    this->Yspeed = Yspeed;
}

