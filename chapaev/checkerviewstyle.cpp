#include "checkerviewstyle.h"

CheckerViewstyle::CheckerViewstyle(BattleSide side)
{
    this->side = side;
    this->pen = QPen(Qt::black);
    if(side == BattleSide::black)
        this->color = QColor(Qt::darkRed);
    if(side == BattleSide::white)
        this->color = QColor(Qt::lightGray);
}

BattleSide CheckerViewstyle::GetSide()
{
    return this->side;
}
