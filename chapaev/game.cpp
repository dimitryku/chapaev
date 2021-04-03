#include "game.h"
#include "math.h"
#include <iostream>

Game::Game()
{
    WhitesTurn = true;
    BlackPoints = 0;
    WhitePoints = 0;
    minSpeed = 0.3;
    speedDecrease = 0.3;
    position = new GamePosition();
}

void Game::InitGameData()
{
    WhitesTurn = true;
    BlackPoints = 0;
    WhitePoints = 0;
}

bool Game::IsWhitesTurn(){ return WhitesTurn; }

void Game::ChangeTurn(){ WhitesTurn = !WhitesTurn; }

GamePosition *Game::GetGamePosition()
{
    return position;
}

bool Game::CheckerIsMoving(Checker ch)
{
    for(MovingChecker mch : movingCheckers)
    {
        if(mch.checker == &ch)
            return true;
    }
    return false;
}


void Game::RecalculateSpeedWithNewChecker(MovingChecker *movingChecker, MovingChecker *standingChecker)
{
    //TODO
}

void Game::RecalculateSpeeds(MovingChecker* first, MovingChecker* second)
{
    if(first->Xspeed == 0 && first->Yspeed == 0 && )
    QVector2D firstVector(first->Xspeed, first->Yspeed);
    QVector2D secondVector(second->Xspeed, second->Yspeed);
    float firstSpeed = firstVector.length();
    float secondSpeed = secondVector.length();
    firstVector.normalize();
    secondVector.normalize();
    // так как вектора нормированы, их координаты стали косинусом и синусом соответственно
    float interactionCos = (firstVector.x()*secondVector.x() + firstVector.y()*secondVector.y())
                    /(firstSpeed*secondSpeed);
    float interactionSin = sqrt(1 - interactionCos*interactionCos);

    // Формула, согласно ф-ле столкновения двух движущихся объектов + косинус разности углов
    // Вес шашек идентичен друг другу.
    first->Xspeed = 2 * secondSpeed * (secondVector.x()*interactionCos + secondVector.y() * interactionSin) * interactionCos
                + firstSpeed * (firstVector.y() * interactionCos - firstVector.x() * interactionSin)
                        * (interactionCos * cos(M_PI/2) + interactionSin * sin(M_PI/2));
    first->Yspeed = 2*secondSpeed*(secondVector.x() * interactionCos + secondVector.y() * interactionSin) * interactionSin
                + firstSpeed * (firstVector.y() * interactionCos - firstVector.x() * interactionSin)
                        * (interactionSin * cos(M_PI/2) + interactionCos * sin(M_PI/2));

    second->Xspeed = 2 * firstSpeed * (firstVector.x() * interactionCos + firstVector.y() * interactionSin) * interactionCos
                + secondSpeed * (secondVector.y() * interactionCos - secondVector.x() * interactionSin)
                        * (interactionCos * cos(M_PI/2) + interactionSin * sin(M_PI/2));
    first->Yspeed = 2 * firstSpeed * (firstVector.x() * interactionCos + firstVector.y() * interactionSin) * interactionSin
                + secondSpeed * (secondVector.y() * interactionCos - secondVector.x() * interactionSin)
                        * (interactionSin * cos(M_PI/2) + interactionCos * sin(M_PI/2));
}

std::queue<Checker*> Game::AffectedCheckers(MovingChecker ch)
{
    std::queue<Checker*> affectedCheckers;
    for(Checker* checker : position->GetBlackCheckers())
    {
        if(checker->GetPosition().distanceToPoint(ch.checker->GetPosition()) < 2*Checker::radius)
            affectedCheckers.push(&*checker);
    }

    for(Checker* checker : position->GetWhiteCheckers())
    {
        if(checker->GetPosition().distanceToPoint(ch.checker->GetPosition()) < 2*Checker::radius)
            affectedCheckers.push(&*checker);
    }

    return affectedCheckers;
}

void Game::PerformMoves(MovingChecker checker)
{
    movingCheckers.clear();
    movingCheckers.push_back(checker);

    int ttt = 0;
    while (movingCheckers.size()!= 0)
    {
        // Сдвигаем шашки
        for(int i = 0; i < movingCheckers.size(); i++)
        {
            movingCheckers[i].checker->IncrementPosition(movingCheckers[i].Xspeed, movingCheckers[i].Yspeed);
            movingCheckers[i].Xspeed -= speedDecrease;
            std:: cout << " " << movingCheckers[i].Xspeed;
            movingCheckers[i].Yspeed -= speedDecrease;
            std:: cout << " " << movingCheckers[i].Yspeed << std::endl;
        }

        // Удаляем остановившиеся шашки
        for(int i = 0; i < movingCheckers.size(); i++)
        {
            if(movingCheckers[i].Xspeed < minSpeed || movingCheckers[i].Yspeed < minSpeed)
            {
                movingCheckers.erase(movingCheckers.begin() + i);
                i--;
            }
        }
        std::cout << ttt++ << " " << movingCheckers.size();

        // Проверяем столкновения и задаем соответствующие скорости
        int numOfCheckersToPerform = movingCheckers.size();
        for(int i = 0; i < numOfCheckersToPerform; i++)
        {
            std::queue<Checker*> affectedCheckers = AffectedCheckers(movingCheckers[i]);
            while(!affectedCheckers.empty())
            {
                if(!CheckerIsMoving(*affectedCheckers.front()))
                {
                    movingCheckers.push_back(MovingChecker(affectedCheckers.front()));
                    affectedCheckers.pop();
                    RecalculateSpeeds(&movingCheckers.at(i), &movingCheckers.at(movingCheckers.size() - 1));
                } else
                {
                    for(MovingChecker c : movingCheckers)
                    {
                        if(c.checker == affectedCheckers.front())
                            RecalculateSpeeds(&movingCheckers.at(i), &c);
                    }
                }
            }
        }
    }

}
