#ifndef PHYSX_H
#define PHYSX_H

#include <vector>
#include <math.h>
#include <queue>

#include "movingchecker.h"
#include "gameposition.h"
#include "initgamedata.h"

class GamePosition;

class Physx
{
public:
    Physx(GamePosition* position);
    void PrepareData(Checker* checker, const QVector2D& speed);
    std::vector<Checker*> MakeStep();

    ~Physx();

private:
    float speedDecrease;
    GamePosition* position;
    std::vector<MovingChecker> movingCheckers;

    float SinVminusPhi(const QVector2D& V, const QVector2D& phi);
    float CosVminusPhi(const QVector2D& V, const QVector2D& phi);
    float CosVplusPhi(const QVector2D& V, const QVector2D& phi);
    float SinVplusPhi(const QVector2D& V, const QVector2D& phi);

    std::queue<Checker*> findAffectedCheckers(const MovingChecker& ch);
    void recalculateSpeeds(MovingChecker* first, MovingChecker* second);
    void RecalculateSpeedWithNewChecker(MovingChecker* movingChecker, MovingChecker* standingChecker);
    void recalculateSpeedsOfMovingCheckers(MovingChecker* first, MovingChecker* second);
    void moveCheckersByOneStep();
    void deleteNotMovingCheckers();
    void performCheckersInteraction();
    int FindCheckerInMovingCheckers(Checker* checker);
    bool checkerIsMoving(const Checker& ch);

};

#endif // PHYSX_H
