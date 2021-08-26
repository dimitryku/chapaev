#ifndef GAME_H
#define GAME_H

#include "PhysX/movingchecker.h"
#include "vector"
#include "gameposition.h"
#include "initgamedata.h"
#include "queue"
#include "PhysX/physx.h"
#include "qt/gameview.h"

class GameView;
class GamePosition;
class Physx;

class Game
{
private:
    int WhitePoints;
    int BlackPoints;
    bool WhitesTurn;
    Physx* physx;
    GamePosition* position;
    GameView* view;

public:
    Game();
    void InitGameData();
    bool IsWhitesTurn();
    void ChangeTurn();
    std::vector<Checker*>& getGamePosition();
    void SetView(GameView* view);

    ~Game();

};

#endif // GAME_H
