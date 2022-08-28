#ifndef CHECKERVIEVSTYLE_H
#define CHECKERVIEVSTYLE_H
#include <QPen>
#include <QColor>
#include <QBrush>

#include "BattleSide.h"

class CheckerViewStyle
{
private:
    QPen pen;
    QColor color;
    QBrush brush;

public:
    CheckerViewStyle(BattleSide side);
    QColor getColor() const {return color;}
    QBrush getBrush() const {return brush;}
    QPen getPen() const {return pen;}
};

#endif // CHECKERVIEVSTYLE_H
