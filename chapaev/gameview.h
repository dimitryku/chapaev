#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItemGroup>

class GameView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit GameView(QObject *parent = nullptr);

signals:

private:
    QGraphicsScene* scene;
    QGraphicsItemGroup* checkers;
    QGraphicsItemGroup* board;

    void SetBoard(int num);

};

#endif // GAMEVIEW_H
