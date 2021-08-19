#include "movingchecker.h"
#include <math.h>

MovingChecker::MovingChecker(Checker *c)
{
    this->checker = c;
    this->speed.setX(0);
    this->speed.setY(0);
}

MovingChecker::MovingChecker(Checker *c, float Xspeed, float Yspeed)
{
    this->checker = c;
    this->speed.setX(Xspeed);
    this->speed.setY(Yspeed);
}

bool MovingChecker::IsMoving()
{
    bool ans = (fabs(speed.x()) > 0.001 && fabs(speed.y()) > 0.001);
    return ans;
}

QVector2D MovingChecker::getSpeed()
{
    return speed;
}

void MovingChecker::increaseXSpeed(float xSpeed)
{
    speed.setX(speed.x() + xSpeed);
}

void MovingChecker::increaseYSpeed(float ySpeed)
{
    speed.setX(speed.y() + ySpeed);
}

void MovingChecker::resetXSpeed()
{
    speed.setX(0);
}

void MovingChecker::resetYSpeed()
{
    speed.setY(0);
}

