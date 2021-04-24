#ifndef QCHECKER_H
#define QCHECKER_H
#include "checker.h"
#include "checkerviewstyle.h"
#include "QGraphicsItem"
#include <QPainter>

class qChecker : public QGraphicsItem
{
private:
    Checker* checker;
    CheckerViewStyle* style;
    BattleSide side;
    QRectF boundingRect() const;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

signals:

public:
    qChecker(Checker *checker, CheckerViewStyle *style, BattleSide side);
    Checker* GetChecker() const;
    CheckerViewStyle* GetViewStyle() const;
    BattleSide GetBatleSide() const;

};

#endif // QCHECKER_H
