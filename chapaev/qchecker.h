#ifndef QCHECKER_H
#define QCHECKER_H
#include "checker.h"
#include "checkerviewstyle.h"
#include "QGraphicsItem"

class qChecker : public QGraphicsItem, public QObject
{
    //Q_OBJECT
private:
    Checker* checker;
    CheckerViewstyle* style;
    BattleSide side;

public:
    qChecker(Checker *checker, CheckerViewstyle *style, BattleSide side);
    Checker* GetChecker() const;
    CheckerViewstyle* GetViewStyle() const;
    BattleSide GetBatleSide() const;

};

#endif // QCHECKER_H
