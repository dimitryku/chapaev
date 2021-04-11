#include "checkervievstyle.h"


CheckerVievstyle::CheckerVievstyle(BattleSide side)
{
    this->side = side;
    this->pen = QPen(Qt::black);
    if(side == BattleSide::black)
        this->color = QColor(Qt::darkRed);
    if(side == BattleSide::white)
        this->color = QColor(Qt::lightGray);
}

BattleSide CheckerVievstyle::GetSide()
{
    return this->side;
}
