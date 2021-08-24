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
    for(size_t i = 0; i < movingCheckers.size(); i++)
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
    // Сохраняем скорость движущейся шашки в удобном формате
    QVector2D oldSpeed = QVector2D(movingChecker->getSpeed().x(), movingChecker->getSpeed().y());
    // создаем вектор, по которому полетит стоящая шашка и нормируем его
    QVector2D strikeVector = QVector2D(standingChecker->checker->GetPosition().x() - movingChecker->checker->GetPosition().x(),
                                       standingChecker->checker->GetPosition().y() - movingChecker->checker->GetPosition().y());
    strikeVector.normalize();
    // по теореме косинусов считаем косинус угла удара
    float strikeAngleCos = (oldSpeed.x() * strikeVector.x() + oldSpeed.y() * strikeVector.y())/oldSpeed.length();

    // Пересчитываем вектора и записываем в шашки
    float newSpeed = oldSpeed.length() * strikeAngleCos;
    strikeVector *=(newSpeed);
    standingChecker->setXSpeed(strikeVector.x());
    standingChecker->setYSpeed(strikeVector.y());
    movingChecker->increaseXSpeed(-1 * strikeVector.x());
    movingChecker->increaseYSpeed(-1 * strikeVector.y());
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
    QVector2D firstVector(first->getSpeed().x(), first->getSpeed().y());
    QVector2D secondVector(second->getSpeed().x(), second->getSpeed().y());
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
    first->setXSpeed(2 * secondSpeed * CosVminusPhi(secondVector, interaction) * interaction.x()
                + firstSpeed * SinVminusPhi(firstVector, interaction) * CosVplusPhi(interaction, piHalf));

    first->setYSpeed(2 * secondSpeed * CosVminusPhi(secondVector, interaction) * interaction.y()
                + firstSpeed * SinVminusPhi(firstVector, interaction) * SinVplusPhi(interaction, piHalf));

    second->setXSpeed(2 * firstSpeed * CosVminusPhi(firstVector, interaction) * interaction.x()
                + secondSpeed * SinVminusPhi(secondVector, interaction) * CosVplusPhi(interaction, piHalf));

    second->setYSpeed(2 * firstSpeed * CosVminusPhi(firstVector, interaction) * interaction.y()
                + secondSpeed * SinVminusPhi(secondVector, interaction) * SinVplusPhi(interaction, piHalf));
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
    for(size_t i = 0; i < movingCheckers.size(); i++)
    {
        movingCheckers[i].checker->IncrementPosition(movingCheckers[i].getSpeed().x(), movingCheckers[i].getSpeed().y());
        if(fabs(movingCheckers[i].getSpeed().x()) > speedDecrease)
            movingCheckers[i].increaseXSpeed(std::copysign(1, movingCheckers[i].getSpeed().x()) * (-1) * speedDecrease);
        else
            movingCheckers[i].setXSpeed(0);
        std:: cout << " " << movingCheckers[i].getSpeed().x();

        if(fabs(movingCheckers[i].getSpeed().y()) > speedDecrease)
            movingCheckers[i].increaseYSpeed(std::copysign(1, movingCheckers[i].getSpeed().y()) * (-1) * speedDecrease);
        else
            movingCheckers[i].setYSpeed(0);
        std:: cout << " " << movingCheckers[i].getSpeed().y() << std::endl;
    }
}

void Physx::DeleteNotMovingCheckers()
{
    for(size_t i = 0; i < movingCheckers.size(); i++)
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
