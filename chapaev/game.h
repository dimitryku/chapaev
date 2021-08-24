#ifndef GAME_H
#define GAME_H

#include "PhysX/movingchecker.h"
#include "vector"
#include "PhysX/gameposition.h"
#include "initgamedata.h"
#include "queue"
#include "PhysX/physx.h"
#include "qt/gameview.h"

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
    Physx* physx;

public:
    Game();
    void InitGameData();
    bool IsWhitesTurn();
    void ChangeTurn();
    GamePosition* GetGamePosition();

    ~Game();

};

#endif // GAME_H
