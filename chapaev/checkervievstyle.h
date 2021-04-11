#ifndef CHECKERVIEVSTYLE_H
#define CHECKERVIEVSTYLE_H
#include "QPen"
#include "QColor"

enum BattleSide {
    white,
    black
};

class CheckerVievstyle
{
private:
    BattleSide side;
public:
    QPen pen;
    QColor color;

    CheckerVievstyle(BattleSide side);
    BattleSide GetSide();
};

#endif // CHECKERVIEVSTYLE_H
