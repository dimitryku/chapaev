#include "qboard.h"

#include <QPainter>

QBoard::QBoard(int xBlocks, int yBlocks)
{
    this->xBlocks = xBlocks;
    this->yBlocks =  yBlocks;
}

QRectF QBoard::boundingRect() const
{
    return QRectF(QPointF(0.0, 0.0), QPointF(xBlocks * rectSize, yBlocks * rectSize));
}

//TODO: check coordinates translation
void QBoard::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)

    painter->setBrush(QBrush(QColor(119, 153, 82))); //TODO change
    for(int i = 0; i < yBlocks; i++)
        for(int j = 0; j < xBlocks; j++)
        {
            if((i + j) % 2 == 1)
                painter->drawRect(rectSize * i, rectSize * j, rectSize, rectSize);
        }

    painter->setBrush(QBrush(QColor(255, 255, 231))); //TODO change
    for(int i = 0; i < yBlocks; i++)
        for(int j = 0; j < xBlocks; j++)
        {
            if((i + j) % 2 != 1)
                painter->drawRect(rectSize * i, rectSize * j, rectSize, rectSize);
        }
}
