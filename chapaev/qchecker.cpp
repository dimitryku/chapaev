#include "qchecker.h"


qChecker::qChecker(Checker *checker, CheckerViewstyle *style, BattleSide side)
{
    this->checker = checker;
    this->style = style;
    this->side = side;
}

Checker *qChecker::GetChecker() const
{
    return checker;
}

CheckerViewstyle *qChecker::GetViewStyle() const
{
    return style;
}

BattleSide qChecker::GetBatleSide() const
{
    return side;
}


