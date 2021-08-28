#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItemGroup>
#include <vector>

#include "game.h"
#include "qcheckersholder.h"
#include "qchecker.h"
#include "qboard.h"
#include "ActiveCheckerBounder.h"

class Game;
class QCheckersHolder;

class GameView : public QGraphicsView
{
    Q_OBJECT
public:
    GameView(Game* game, QObject *parent = nullptr);
    static float rectSize;

signals:
public slots:
    void DragStarted(QChecker* checker, QPointF pos);
    void DragFinished(QChecker* checker, QVector2D diff);

private:
    Game* game;
    QGraphicsScene* scene;
    QBoard* board;
    QCheckersHolder* checkersHolder;
    ActiveCheckerBounder* checkerBounder;
    bool dragStarted;

    void SetCheckers(Game* game, int num);

};

#endif // GAMEVIEW_H
