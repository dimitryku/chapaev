#ifndef CHECKERVIEVSTYLE_H
#define CHECKERVIEVSTYLE_H
#include "QPen"
#include "QColor"
#include "QBrush"

#include "BattleSide.h"

class CheckerViewStyle
{
private:
public:
    CheckerViewStyle(BattleSide side);
    QPen pen;
    QColor color;
    QBrush brush;

};

#endif // CHECKERVIEVSTYLE_H
