#ifndef MOVINGCHECKER_H
#define MOVINGCHECKER_H
#include "checker.h"


class MovingChecker
{
public:
    explicit MovingChecker(Checker *c);
    MovingChecker(Checker *c, int Xspeed, int Yspeed,);
    int Xspeed;
    int Yspeed;
    Checker * checker;
};

#endif // MOVINGCHECKER_H
