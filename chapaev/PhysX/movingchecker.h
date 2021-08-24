#ifndef MOVINGCHECKER_H
#define MOVINGCHECKER_H
#include "checker.h"


class MovingChecker
{
public:
    explicit MovingChecker(Checker *c);
    MovingChecker(Checker *c, float Xspeed, float Yspeed);
    bool IsMoving();
    QVector2D getSpeed();
    void increaseXSpeed(float delta);
    void increaseYSpeed(float delta);
    void setXSpeed(float xSpeed);
    void setYSpeed(float ySpeed);
    Checker* getChecker();

private:
    QVector2D speed;
    Checker * checker;

};

#endif // MOVINGCHECKER_H
