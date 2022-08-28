#ifndef QINPUTLINE_H
#define QINPUTLINE_H

#include <QGraphicsLineItem>
#include <QGraphicsSceneMouseEvent>

class InputLine : public QGraphicsLineItem
{
public:
    InputLine();
    void SetStartPoint(const QPointF& point);
    void SetMousePos(const QPointF& point);

private:
    QPointF startPoint;

protected:
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
};

#endif // QINPUTLINE_H
