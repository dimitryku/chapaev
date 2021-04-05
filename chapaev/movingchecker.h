#ifndef MOVINGCHECKER_H
#define MOVINGCHECKER_H
#include "checker.h"


class MovingChecker
{
public:
    float Xspeed;
    float Yspeed;
    Checker * checker;

    explicit MovingChecker(Checker *c);
    MovingChecker(Checker *c, float Xspeed, float Yspeed);
    bool SpeedIsGood(float speed);
    bool IsNotMoving();
};

#endif // MOVINGCHECKER_H
