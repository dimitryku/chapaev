#include "physx.h"
#include <iostream>

Physx::Physx(GamePosition* pos)
{
    speedDecrease = 0.3;
    position = pos;
}


bool Physx::CheckerIsMoving(Checker ch)
{
    for(MovingChecker mch : movingCheckers)
    {
        if(mch.checker == &ch)
            return true;
    }
    return false;
}

int Physx::FindCheckerInMovingCheckers(Checker* checker)
{
    for(int i = 0; i < movingCheckers.size(); i++)
    {
        if(movingCheckers[i].checker == checker)
        {
            return i;
        }
    }
    return -1;
}

void Physx::RecalculateSpeedWithNewChecker(MovingChecker *movingChecker, MovingChecker *standingChecker)
{
    // Сохраняем скорость движущейся шашшшки в удобном формате
    QVector2D oldSpeed = QVector2D(movingChecker->Xspeed, movingChecker->Yspeed);
    // создаем вектор, по которому полетит стоящая шашка и нормируем его
    QVector2D strikeVector = QVector2D(standingChecker->checker->GetPosition().x() - movingChecker->checker->GetPosition().x(),
                                       standingChecker->checker->GetPosition().y() - movingChecker->checker->GetPosition().y());
    strikeVector.normalize();
    // по теореме косинусов считаем косинус угла удара
    float strikeAngleCos = (oldSpeed.x() * strikeVector.x() + oldSpeed.y() * strikeVector.y())/oldSpeed.length();

    // Пересчитываем вектора и записываем в шашки
    float newSpeed = oldSpeed.length() * strikeAngleCos;
    strikeVector *=(newSpeed);
    standingChecker->Xspeed = strikeVector.x();
    standingChecker->Yspeed = strikeVector.y();
    movingChecker->Xspeed = oldSpeed.x() - strikeVector.x();
    movingChecker->Yspeed = oldSpeed.y() - strikeVector.y();
}

float Physx::SinVminusPhi(QVector2D V, QVector2D phi)
{
    return (V.y() * phi.x() - V.x() * phi.y());
}

float Physx::CosVminusPhi(QVector2D V, QVector2D phi)
{
    return (V.x() * phi.x() - V.y() * phi.y());
}

float Physx::CosVplusPhi(QVector2D V, QVector2D phi)
{
    return (V.x() * phi.x() + V.y() * phi.y());
}

float Physx::SinVplusPhi(QVector2D V, QVector2D phi)
{
    return (V.y() * phi.x() + V.x() * phi.y());
}

void Physx::RecalculateSpeedsOfMovingCheckers(MovingChecker* first, MovingChecker* second)
{
    QVector2D firstVector(first->Xspeed, first->Yspeed);
    QVector2D secondVector(second->Xspeed, second->Yspeed);
    float firstSpeed = firstVector.length();
    float secondSpeed = secondVector.length();
    firstVector.normalize();
    secondVector.normalize();
    QVector2D piHalf(cos(M_PI/2), sin(M_PI/2));
    QVector2D interaction;
    // так как вектора нормированы, их координаты стали косинусом и синусом соответственно
    interaction.setX((firstVector.x() * secondVector.x() + firstVector.y() * secondVector.y())
                    / (firstSpeed * secondSpeed));
    interaction.setY(sqrt(1 - interaction.x() * interaction.x()));

    // Формула, согласно ф-ле столкновения двух движущихся объектов + косинус разности углов
    // Вес шашек идентичен друг другу.
    first->Xspeed = 2 * secondSpeed * CosVminusPhi(secondVector, interaction) * interaction.x()
                + firstSpeed * SinVminusPhi(firstVector, interaction) * CosVplusPhi(interaction, piHalf);

    first->Yspeed = 2 * secondSpeed * CosVminusPhi(secondVector, interaction) * interaction.y()
                + firstSpeed * SinVminusPhi(firstVector, interaction) * SinVplusPhi(interaction, piHalf);

    second->Xspeed = 2 * firstSpeed * CosVminusPhi(firstVector, interaction) * interaction.x()
                + secondSpeed * SinVminusPhi(secondVector, interaction) * CosVplusPhi(interaction, piHalf);

    first->Yspeed = 2 * firstSpeed * CosVminusPhi(firstVector, interaction) * interaction.y()
                + secondSpeed * SinVminusPhi(secondVector, interaction) * SinVplusPhi(interaction, piHalf);
}

void Physx::RecalculateSpeeds(MovingChecker* first, MovingChecker* second)
{
    // Вызов функции перерассчета в зависимости от движений шашек
    // Ситуация, когда обе шашки стоят на месте, невозможна в связи с логикой их выявления
    if(!first->IsMoving())
    {
        RecalculateSpeedWithNewChecker(second, first);
        return;
    }

    if(!second->IsMoving())
    {
        RecalculateSpeedWithNewChecker(first, second);
        return;
    }

    RecalculateSpeedsOfMovingCheckers(first, second);

}

std::queue<Checker*> Physx::FindAffectedCheckers(MovingChecker ch)
{
    std::queue<Checker*> affectedCheckers;
    for(Checker* checker : position->GetCheckers())
    {
        if(!checker->GetOutOfGame()) {
            if(checker->GetPosition().distanceToPoint(ch.checker->GetPosition()) <= 2*Checker::radius
                    && checker->GetPosition().distanceToPoint(ch.checker->GetPosition()) > 0.001)
                affectedCheckers.push(&*checker);
        }
    }

    return affectedCheckers;
}

void Physx::MoveCheckersByOneStep()
{
    for(int i = 0; i < movingCheckers.size(); i++)
    {
        movingCheckers[i].checker->IncrementPosition(movingCheckers[i].Xspeed, movingCheckers[i].Yspeed);
        if(fabs(movingCheckers[i].Xspeed) > speedDecrease)
            movingCheckers[i].Xspeed -= std::copysign(1, movingCheckers[i].Xspeed) * speedDecrease;
        else
            movingCheckers[i].Xspeed = 0;
        std:: cout << " " << movingCheckers[i].Xspeed;

        if(fabs(movingCheckers[i].Yspeed) > speedDecrease)
            movingCheckers[i].Yspeed -= std::copysign(1, movingCheckers[i].Yspeed) * speedDecrease;
        else
            movingCheckers[i].Yspeed = 0;
        std:: cout << " " << movingCheckers[i].Yspeed << std::endl;
    }
}

void Physx::DeleteNotMovingCheckers()
{
    for(int i = 0; i < movingCheckers.size(); i++)
    {
        if(!movingCheckers[i].IsMoving())
        {
            movingCheckers.erase(movingCheckers.begin() + i);
            i--;
        }
    }
}

void Physx::PerformCheckersInteraction()
{
    int numOfCheckersToPerform = movingCheckers.size();
    for(int i = 0; i < numOfCheckersToPerform; i++)
    {
        std::queue<Checker*> affectedCheckers = FindAffectedCheckers(movingCheckers[i]);
        while(!affectedCheckers.empty())
        {
            // Проверить работу, если проявятся баги - вернуть
            // Если движущаяся шашка отдала всю свою скорость, на остальные она не влияет
//            if(movingCheckers[i].IsNotMoving())
//            {
//                for(int j = 0; j < affectedCheckers.size(); j++)
//                    affectedCheckers.pop();
//                break;
//            }

            // Проверяем, какой алгоритм пересчета скоростей выбрать
            if(!CheckerIsMoving(*affectedCheckers.front()))
            {
                movingCheckers.push_back(MovingChecker(affectedCheckers.front()));
                RecalculateSpeeds(&movingCheckers.at(i), &movingCheckers.at(movingCheckers.size() - 1));
            } else
            {
                int num = FindCheckerInMovingCheckers(affectedCheckers.front());
                RecalculateSpeeds(&movingCheckers.at(i), &movingCheckers.at(num));
            }
            affectedCheckers.pop();
        }
    }
}

void Physx::PerformMoves(MovingChecker checker)
{
    movingCheckers.clear();
    movingCheckers.push_back(checker);

    int ttt = 0;
    while (movingCheckers.size()!= 0)
    {
        std::cout << ttt++ << " (" << movingCheckers.size() << ") " << std::endl;
        // Сдвигаем шашки
        MoveCheckersByOneStep();

        // Удаляем остановившиеся шашки
        DeleteNotMovingCheckers();

        // Проверяем столкновения и задаем соответствующие скорости
        PerformCheckersInteraction();
    }

}
