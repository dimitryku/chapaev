#include "checkerviewstyle.h"

CheckerViewStyle::CheckerViewStyle(BattleSide side)
{
    this->pen = QPen(Qt::black);
    if(side == BattleSide::black)
        this->color = QColor(Qt::darkRed);
    else
        this->color = QColor(Qt::lightGray);
    brush = QBrush(color);
}

