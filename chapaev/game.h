#ifndef GAME_H
#define GAME_H

#include "movingchecker.h"
#include "vector"
#include "PhysX/gameposition.h"
#include "initgamedata.h"
#include "queue"
#include "PhysX/physx.h"
#include "gameview.h"

class GamePosition;
class GameView;
class Physx;

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
    Game();
    void InitGameData();
    bool IsWhitesTurn();
    void ChangeTurn();
    GamePosition* GetGamePosition();

    ~Game();

};

#endif // GAME_H
