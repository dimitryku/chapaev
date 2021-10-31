#ifndef GAME_H
#define GAME_H

#include <vector>
#include <queue>
#include <QTimer>
#include <math.h>

#include "PhysX/movingchecker.h"
#include "gameposition.h"
#include "BattleSide.h"

class GameView;
class GamePosition;
class Physx;

class Game : public QObject
{
    Q_OBJECT

public:
    Game();
    void ChangeTurn();
    std::vector<Checker*>& GetGamePosition();
    void SetView(GameView* view);
    bool ManipulationAccepted(BattleSide side);
    void StartMovement(Checker* checker, QVector2D moveInput);
    void FinishMovement();

    ~Game();

protected slots:
    void MakeStep();

private:
    int whitePoints;
    int blackPoints;
    bool interfaceIsActive;
    BattleSide currentSide;
    Physx* physx;
    GamePosition* position;
    GameView* view;
    QTimer* timer;

};

#endif // GAME_H
