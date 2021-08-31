#ifndef QCHECKER_H
#define QCHECKER_H
#include "PhysX/checker.h"
#include "checkerviewstyle.h"
#include "QGraphicsItem"
#include <QPainter>
#include <QGraphicsSceneMouseEvent>

class QChecker : public QObject, public QGraphicsItem
{
    Q_OBJECT

private:
    Checker* checker;
    CheckerViewStyle* style;
    BattleSide side;
    //QRectF boundingRect() const;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QPointF mousePos;

signals:
    void Pressed(QChecker* checker, QPointF mousePos);
    void Released(QChecker* checker, QVector2D diff);

public:
    QRectF boundingRect() const;
    QChecker(Checker *checker, CheckerViewStyle *style, BattleSide side);
    Checker* GetChecker() const;
    CheckerViewStyle* GetViewStyle() const;
    BattleSide GetBatleSide() const;
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);


};

#endif // QCHECKER_H
