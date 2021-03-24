#include "checker.h"

Checker::Checker(QObject *parent) : QObject(parent)
{
}

QVector2D Checker::GetPosition()
{
    return position;
}

void Checker::SetPosition(QVector2D position)
{
    this->position = position;
}
