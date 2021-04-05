#ifndef GAME_H
#define GAME_H
#include "movingchecker.h"
#include "vector"
#include "gameposition.h"
#include "startgamedata.h"
#include "queue"
#include "physx.h"

class Game
{
private:
    int WhitePoints;
    int BlackPoints;
    bool WhitesTurn;
    GamePosition* position;

public:
    Physx* physx;
    Game();
    void InitGameData();
    bool IsWhitesTurn();
    void ChangeTurn();
    GamePosition* GetGamePosition();

    ~Game();

};

#endif // GAME_H
