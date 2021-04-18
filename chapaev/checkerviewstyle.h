#ifndef CHECKERVIEVSTYLE_H
#define CHECKERVIEVSTYLE_H
#include "QPen"
#include "QColor"
#include "QPainter"
#include "BattleSide.h"

class CheckerViewstyle
{
private:
public:
    CheckerViewstyle(BattleSide side);
    QPen pen;
    QColor color;
    QPainter* painter;

};

#endif // CHECKERVIEVSTYLE_H
