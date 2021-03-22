#include "checker.h"

Checker::Checker(QObject *parent) : QObject(parent)
{
}

QVector2D Checker::GetPosition()
{
    return position;
}
