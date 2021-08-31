#ifndef MOVINGCHECKER_H
#define MOVINGCHECKER_H
#include <math.h>

#include "checker.h"

class MovingChecker
{
public:
    explicit MovingChecker(Checker *c);
    MovingChecker(Checker *c, float Xspeed, float Yspeed);
    MovingChecker(Checker *c, QVector2D speed);
    bool IsMoving();
    QVector2D getSpeed();
    void IncreaseSpeed(QVector2D delta);
    void IncreaseXSpeed(float delta);
    void IncreaseYSpeed(float delta);
    void SetXSpeed(float xSpeed);
    void SetYSpeed(float ySpeed);
    Checker* GetChecker();
    void MakeStep();

private:
    QVector2D speed;
    Checker * checker;

};

#endif // MOVINGCHECKER_H
