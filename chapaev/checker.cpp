#include "checker.h"

float Checker::radius = 5;

Checker::Checker()
{
    isOutOfGame = false;
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

Checker::Checker(Checker &checker)
{
    this->position = checker.position;
    this->isOutOfGame = checker.isOutOfGame;
}

QVector2D Checker::GetPosition() { return position; }
