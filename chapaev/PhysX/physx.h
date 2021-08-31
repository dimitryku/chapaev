#ifndef PHYSX_H
#define PHYSX_H

#include <vector>
#include "math.h"
#include <queue>

#include "movingchecker.h"
#include "gameposition.h"
#include "initgamedata.h"

class GamePosition;

class Physx
{
public:
    Physx(GamePosition* position);
    void PrepareData(Checker* checker, QVector2D speed);
    std::vector<Checker*> MakeStep();

    void PerformMoves(MovingChecker checker);

    ~Physx();

private:
    float speedDecrease;
    float minSpeed;
    GamePosition* position;
    std::vector<MovingChecker> movingCheckers;

    float SinVminusPhi(QVector2D V, QVector2D phi);
    float CosVminusPhi(QVector2D V, QVector2D phi);
    float CosVplusPhi(QVector2D V, QVector2D phi);
    float SinVplusPhi(QVector2D V, QVector2D phi);

    std::queue<Checker*> FindAffectedCheckers(MovingChecker ch);
    void RecalculateSpeeds(MovingChecker* first, MovingChecker* second);
    void RecalculateSpeedWithNewChecker(MovingChecker* movingChecker, MovingChecker* standingChecker);
    void RecalculateSpeedsOfMovingCheckers(MovingChecker* first, MovingChecker* second);
    void MoveCheckersByOneStep();
    void DeleteNotMovingCheckers();
    void PerformCheckersInteraction();
    int FindCheckerInMovingCheckers(Checker* checker);
    bool CheckerIsMoving(Checker ch);

};

#endif // PHYSX_H
