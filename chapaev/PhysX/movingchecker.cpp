#include "movingchecker.h"

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

void MovingChecker::IncreaseSpeed(QVector2D delta)
{
    speed += delta;
}

void MovingChecker::IncreaseXSpeed(float delta)
{
    speed.setX(speed.x() + delta);
}

void MovingChecker::IncreaseYSpeed(float delta)
{
    speed.setY(speed.y() + delta);
}

void MovingChecker::SetXSpeed(float xSpeed)
{
    speed.setX(xSpeed);
}

void MovingChecker::SetYSpeed(float ySpeed)
{
    speed.setY(ySpeed);
}

Checker* MovingChecker::GetChecker()
{
    return checker;
}

void MovingChecker::MakeStep()
{
    checker->IncrementPosition(speed.x(), speed.y());
}

