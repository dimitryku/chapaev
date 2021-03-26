#include "checker.h"

Checker::Checker(QObject *parent) : QObject(parent)
{
    isOutOfGame = false;
}

void Checker::SetPosition(QVector2D position) { this->position = position; }

void Checker::SetOutOfGame(bool t)
{
    this->isOutOfGame = t;
}

bool Checker::GetOutOfGame()
{
    return isOutOfGame;
}

QVector2D Checker::GetPosition() { return position; }
