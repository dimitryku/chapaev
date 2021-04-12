#ifndef CHECKERVIEVSTYLE_H
#define CHECKERVIEVSTYLE_H
#include "QPen"
#include "QColor"

enum BattleSide {
    white,
    black
};

class CheckerViewstyle
{
private:
    BattleSide side;
public:
    QPen pen;
    QColor color;

    CheckerViewstyle(BattleSide side);
    BattleSide GetSide();
};

#endif // CHECKERVIEVSTYLE_H
