#include "inputline.h"

InputLine::InputLine()
{
    QPen* newPen = new QPen();
    newPen->setStyle(Qt::SolidLine);
    newPen->setColor(Qt::blue);
    newPen->setWidth(2);
    this->setPen(*newPen);
    delete newPen;
    this->setLine(1, 1, 500, 500);
}

void InputLine::SetStartPoint(QPointF point)
{
    startPoint = point;
    this->setLine(startPoint.x(), startPoint.y(), point.x(), point.y());
}

void InputLine::SetMousePos(QPointF point)
{
    this->setLine(startPoint.x(), startPoint.y(), point.x(), point.y());
}
