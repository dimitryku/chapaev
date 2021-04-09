#include "movingchecker.h"
#include <math.h>

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

bool MovingChecker::IsMoving()
{
    bool ans = (fabs(Xspeed) > 0.001 && fabs(Yspeed)> 0.001);
    return ans;
}

