#ifndef GAME_H
#define GAME_H

#include "vector"
#include "queue"

#include "PhysX/movingchecker.h"
#include "PhysX/physx.h"
#include "qt/gameview.h"
#include "gameposition.h"
#include "initgamedata.h"
#include "BattleSide.h"

class GameView;
class GamePosition;
class Physx;

class Game
{
private:
    int whitePoints;
    int blackPoints;
    bool interfaceIsActive;
    BattleSide currentSide;
    Physx* physx;
    GamePosition* position;
    GameView* view;

public:
    Game();
    void ChangeTurn();
    std::vector<Checker*>& GetGamePosition();
    void SetView(GameView* view);
    bool ManipulationAccepted(BattleSide side);
    void StartMovement(Checker* checker, QVector2D moveInput);

    ~Game();

};

#endif // GAME_H
