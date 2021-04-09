#include "checker.h"

Checker::Checker()
{
    isOutOfGame = false;
    radius = 5;
}

void Checker::SetPosition(QVector2D position) { this->position = position; }

void Checker::SetOutOfGame(bool t)
{
    this->isOutOfGame = t;
}

void Checker::IncrementPosition(float x, float y)
{
    this->position.setX(this->position.x() + x);
    this->position.setY(this->position.y() + y);
}

bool Checker::GetOutOfGame()
{
    return isOutOfGame;
}

void Checker::SetRadius(float rad)
{
    if(rad > 0)
        radius = rad;
    else
        radius = 5;
}

float Checker::GetRadius() { return radius; }

Checker::Checker(Checker &checker)
{
    this->position = checker.position;
    this->isOutOfGame = checker.isOutOfGame;
}

QVector2D Checker::GetPosition() { return position; }
