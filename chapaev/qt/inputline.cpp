#include "inputline.h"

#include <QPen>

InputLine::InputLine()
{
    QPen pen;
    pen.setStyle(Qt::SolidLine);
    pen.setColor(Qt::blue);
    pen.setWidth(2);
    this->setPen(pen);
    this->setLine(1, 1, 500, 500);
}

void InputLine::SetStartPoint(const QPointF& point)
{
    startPoint = point;
    this->setLine(startPoint.x(), startPoint.y(), point.x(), point.y());
}

void InputLine::SetMousePos(const QPointF& point)
{
    this->setLine(startPoint.x(), startPoint.y(), point.x(), point.y());
}

void InputLine::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    QPointF finishPoint = event->pos();
    setLine(startPoint.x(), startPoint.y(), finishPoint.x(), finishPoint.y());
}
