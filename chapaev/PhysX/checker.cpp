#include "checker.h"

float Checker::radius = 30;

Checker::Checker()
{
    isOutOfGame = false;
}

void Checker::setPosition(const QVector2D& position)
{
    this->position = position;
}

void Checker::setOutOfGame(bool value)
{
    this->isOutOfGame = value;
}

void Checker::incrementPosition(const QVector2D& delta)
{
    this->position.setX(this->position.x() + delta.x());
    this->position.setY(this->position.y() + delta.y());
}

bool Checker::getOutOfGame() const
{
    return isOutOfGame;
}

Checker::Checker(const Checker &checker)
{
    this->position = checker.position;
    this->isOutOfGame = checker.isOutOfGame;
}

QVector2D Checker::getPosition() const
{
    return position;
}
