#include "checkerviewstyle.h"

CheckerViewstyle::CheckerViewstyle(BattleSide side)
{
    this->pen = QPen(Qt::black);
    if(side == BattleSide::black)
        this->color = QColor(Qt::darkRed);
    else
        this->color = QColor(Qt::lightGray);
    painter = new QPainter();
    painter->setPen(pen);
    painter->setBrush(color);

}

