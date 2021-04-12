#ifndef QCHECKER_H
#define QCHECKER_H
#include "checker.h"
#include "checkerviewstyle.h"
#include "QGraphicsItem"


class qChecker : QGraphicsItem
{
private:
    Checker* checker;
    CheckerViewstyle* style;

public:
    qChecker(Checker* ch, CheckerViewstyle* st);
    Checker* GetChecker() const;
    CheckerViewstyle* GetViewStyle() const;

};

#endif // QCHECKER_H
