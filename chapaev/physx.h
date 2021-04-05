#ifndef PHYSX_H
#define PHYSX_H
#include "movingchecker.h"
#include "vector"
#include "math.h"
#include "gameposition.h"
#include "startgamedata.h"
#include "queue"


class Physx
{
private:
    float minSpeed;
    float speedDecrease;
    std::vector<MovingChecker> movingCheckers;
    void RecalculateSpeedWithNewChecker(MovingChecker* movingChecker, MovingChecker* standingChecker);
    GamePosition* position;
public:
    Physx(GamePosition* pos);

    void PerformMoves(MovingChecker checker);
    bool CheckerIsMoving(Checker ch);
    void RecalculateSpeeds(MovingChecker* first, MovingChecker* second);
    std::queue<Checker*> AffectedCheckers(MovingChecker ch);
};

#endif // PHYSX_H
