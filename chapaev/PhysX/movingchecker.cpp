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

MovingChecker::MovingChecker(Checker *c, QVector2D speed)
{
    this->checker = c;
    this->speed = speed;
}

bool MovingChecker::IsMoving()
{
    bool ans = (fabs(speed.x()) > 0.001 || fabs(speed.y()) > 0.001);
    return ans;
}

QVector2D MovingChecker::getSpeed()
{
    return speed;
}

void MovingChecker::increaseSpeed(QVector2D delta)
{
    speed += delta;
}

void MovingChecker::increaseXSpeed(float delta)
{
    speed.setX(speed.x() + delta);
}

void MovingChecker::increaseYSpeed(float delta)
{
    speed.setY(speed.y() + delta);
}

void MovingChecker::setXSpeed(float xSpeed)
{
    speed.setX(xSpeed);
}

void MovingChecker::setYSpeed(float ySpeed)
{
    speed.setY(ySpeed);
}

Checker* MovingChecker::getChecker()
{
    return checker;
}

void MovingChecker::MakeStep()
{
    checker->IncrementPosition(speed.x(), speed.y());
}

