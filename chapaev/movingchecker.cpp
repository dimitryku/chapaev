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

bool MovingChecker::SpeedIsGood(float speed)
{
    float curSpeed = (QVector2D(Xspeed, Yspeed)).length();
    bool ans = (fabs(fabs(Xspeed) - speed) > 0.001 && fabs(fabs(Yspeed) - speed) > 0.001);
    return ans;
}

