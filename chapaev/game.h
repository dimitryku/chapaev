#ifndef GAME_H
#define GAME_H
#include "movingchecker.h"
#include "vector"
#include "gameposition.h"
#include "startgamedata.h"
#include "queue"
#include "physx.h"
#include "gameview.h"

class Game
{
private:
    int WhitePoints;
    int BlackPoints;
    bool WhitesTurn;
    GamePosition* position;
    GameView* view;

public:
    Physx* physx;
    Game(GameView* v);
    void InitGameData();
    bool IsWhitesTurn();
    void ChangeTurn();
    GamePosition* GetGamePosition();

    ~Game();

};

#endif // GAME_H
