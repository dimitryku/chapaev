#ifndef QINPUTLINE_H
#define QINPUTLINE_H

#include "QGraphicsLineItem"
#include "QPen"
#include "QGraphicsSceneMouseEvent"

class InputLine : public QGraphicsLineItem
{
public:
    InputLine();
    void SetStartPoint(QPointF point);
    void SetMousePos(QPointF point);

private:
    QPointF startPoint;

    // QGraphicsItem interface
protected:
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
};

#endif // QINPUTLINE_H
