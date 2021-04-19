#ifndef PHYSX_H
#define PHYSX_H
#include "movingchecker.h"
#include <vector>
#include "math.h"
#include "gameposition.h"
#include "initgamedata.h"
#include <queue>

class GamePosition;

class Physx
{
private:
    float speedDecrease;
    GamePosition* position;
    std::vector<MovingChecker> movingCheckers;

    float SinVminusPhi(QVector2D V, QVector2D phi);
    float CosVminusPhi(QVector2D V, QVector2D phi);
    float CosVplusPhi(QVector2D V, QVector2D phi);
    float SinVplusPhi(QVector2D V, QVector2D phi);
    void RecalculateSpeedWithNewChecker(MovingChecker* movingChecker, MovingChecker* standingChecker);
    void RecalculateSpeedsOfMovingCheckers(MovingChecker* first, MovingChecker* second);
    void MoveCheckersByOneStep();
    void DeleteNotMovingCheckers();
    void PerformCheckersInteraction();
    int FindCheckerInMovingCheckers(Checker* checker);


public:
    Physx(GamePosition* pos);
    void PerformMoves(MovingChecker checker);
    bool CheckerIsMoving(Checker ch);
    void RecalculateSpeeds(MovingChecker* first, MovingChecker* second);
    std::queue<Checker*> FindAffectedCheckers(MovingChecker ch);
};

#endif // PHYSX_H
