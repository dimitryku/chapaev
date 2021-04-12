#include "qchecker.h"


qChecker::qChecker(Checker *ch, CheckerViewstyle *st)
{
    checker = ch;
    style = st;
}

Checker *qChecker::GetChecker() const
{
    return checker;
}

CheckerViewstyle *qChecker::GetViewStyle() const
{
    return style;
}


