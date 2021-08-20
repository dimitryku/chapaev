#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItemGroup>
#include <vector>
#include "game.h"
#include "qcheckerholder.h"
#include "qchecker.h"

class Game;
class qCheckerHolder;

class GameView : public QGraphicsView
{
    Q_OBJECT
public:
    GameView(QObject *parent = nullptr, Game* game = 0);
    static float rectSize;

signals:

private:

    QGraphicsScene* scene;
    QGraphicsItemGroup* checkers;
    QGraphicsItemGroup* board;
    qCheckerHolder* checkersHolder;

    void SetCheckers(Game* game, int num);
    void SetBoard(int num);

};

#endif // GAMEVIEW_H
