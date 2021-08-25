#ifndef QCHECKER_H
#define QCHECKER_H
#include "PhysX/checker.h"
#include "checkerviewstyle.h"
#include "QGraphicsItem"
#include <QPainter>
#include <QGraphicsSceneMouseEvent>

class qChecker : public QGraphicsItem
{
private:
    Checker* checker;
    CheckerViewStyle* style;
    BattleSide side;
    QRectF boundingRect() const;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QPointF mousePos;

signals:

public:
    qChecker(Checker *checker, CheckerViewStyle *style, BattleSide side);
    Checker* GetChecker() const;
    CheckerViewStyle* GetViewStyle() const;
    BattleSide GetBatleSide() const;
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);


};

#endif // QCHECKER_H
