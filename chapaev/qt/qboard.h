#ifndef QBOARD_H
#define QBOARD_H

#include "QGraphicsItem"
#include "QPainter"

#include "PhysX/checker.h"

class QBoard : public QGraphicsItem
{
public:
    QBoard(int xBlocks, int yBlocks);

private:
    int xBlocks;
    int yBlocks;
    const float rectSize = Checker::radius * 2 + 20; //TODO check

    QRectF boundingRect() const;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

};

#endif // QBOARD_H
