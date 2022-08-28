#ifndef QCHECKERDRAGVISUALISER_H
#define QCHECKERDRAGVISUALISER_H

#include <QGraphicsItem>

class QChecker;

class ActiveCheckerBounder: public QGraphicsItem
{
public:
    explicit ActiveCheckerBounder();
    void AddBoundingCircle(QChecker* checker);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;

    ~ActiveCheckerBounder();

private:
    QPointF centerPoint;
    float radius;
};

#endif // QCHECKERDRAGVISUALISER_H
