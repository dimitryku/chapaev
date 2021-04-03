#ifndef GAME_H
#define GAME_H
#include "movingchecker.h"
#include "vector"
#include "gameposition.h"
#include "startgamedata.h"
#include "queue"

class Game
{
private:
    float minSpeed;
    float speedDecrease;
    std::vector<MovingChecker> movingCheckers;
    int WhitePoints;
    int BlackPoints;
    bool WhitesTurn;
    GamePosition* position;
    void RecalculateSpeedWithNewChecker(MovingChecker* movingChecker, MovingChecker* standingChecker);

public:
    Game();
    void InitGameData();
    bool IsWhitesTurn();
    void ChangeTurn();
    GamePosition* GetGamePosition();
    void PerformMoves(MovingChecker checker);
    bool CheckerIsMoving(Checker ch);
    void RecalculateSpeeds(MovingChecker* first, MovingChecker* second);
    std::queue<Checker*> AffectedCheckers(MovingChecker ch);

};

#endif // GAME_H
