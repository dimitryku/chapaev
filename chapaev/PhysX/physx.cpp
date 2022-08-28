#include "physx.h"

Physx::Physx(GamePosition* position)
{
    speedDecrease = 0.3;
    this->position = position;
}

void Physx::PrepareData(Checker *checker, const QVector2D& speed)
{
    // В этот момент вектор пуст, так как иначе мы бы
    // продолжали движения
    movingCheckers.push_back(MovingChecker(checker, speed));
}

std::vector<Checker *> Physx::MakeStep()
{
    // Запоминаем какие шашки были передвинуты во время шага
    std::vector<Checker *> affectedCheckers;
    for(MovingChecker mch : movingCheckers)
        affectedCheckers.push_back(mch.GetChecker());

    // Сдвигаем шашки
    moveCheckersByOneStep();

    // Удаляем остановившиеся шашки
    deleteNotMovingCheckers();

    // Проверяем столкновения и задаем соответствующие скорости
    performCheckersInteraction();

    // Возвращаем список шашек на перерисовку
    return affectedCheckers;
}


bool Physx::checkerIsMoving(const Checker& ch)
{
    return std::any_of(movingCheckers.begin(), movingCheckers.end(), [&ch](const MovingChecker& mch){ return mch.GetChecker() == &ch; });
}

int Physx::FindCheckerInMovingCheckers(Checker* checker)
{
    for(size_t i = 0; i < movingCheckers.size(); i++)
    {
        if(movingCheckers[i].GetChecker() == checker)
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
    QVector2D strikeVector = QVector2D(standingChecker->GetChecker()->getPosition().x() - movingChecker->GetChecker()->getPosition().x(),
                                       standingChecker->GetChecker()->getPosition().y() - movingChecker->GetChecker()->getPosition().y());
    strikeVector.normalize();
    // по теореме косинусов считаем косинус угла удара
    float strikeAngleCos = (oldSpeed.x() * strikeVector.x() + oldSpeed.y() * strikeVector.y())/oldSpeed.length();

    // Пересчитываем вектора и записываем в шашки
    float newSpeed = oldSpeed.length() * strikeAngleCos;
    strikeVector *=(newSpeed);
    standingChecker->SetXSpeed(strikeVector.x());
    standingChecker->SetYSpeed(strikeVector.y());
    movingChecker->IncreaseXSpeed(-1 * strikeVector.x());
    movingChecker->IncreaseYSpeed(-1 * strikeVector.y());
}

float Physx::SinVminusPhi(const QVector2D& V, const QVector2D& phi)
{
    return (V.y() * phi.x() - V.x() * phi.y());
}

float Physx::CosVminusPhi(const QVector2D& V, const QVector2D& phi)
{
    return (V.x() * phi.x() - V.y() * phi.y());
}

float Physx::CosVplusPhi(const QVector2D& V, const QVector2D& phi)
{
    return (V.x() * phi.x() + V.y() * phi.y());
}

float Physx::SinVplusPhi(const QVector2D& V, const QVector2D& phi)
{
    return (V.y() * phi.x() + V.x() * phi.y());
}

void Physx::recalculateSpeedsOfMovingCheckers(MovingChecker* first, MovingChecker* second)
{
    QVector2D firstVector(first->getSpeed());
    QVector2D secondVector(second->getSpeed());
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
    first->SetXSpeed(2 * secondSpeed * CosVminusPhi(secondVector, interaction) * interaction.x()
                + firstSpeed * SinVminusPhi(firstVector, interaction) * CosVplusPhi(interaction, piHalf));

    first->SetYSpeed(2 * secondSpeed * CosVminusPhi(secondVector, interaction) * interaction.y()
                + firstSpeed * SinVminusPhi(firstVector, interaction) * SinVplusPhi(interaction, piHalf));

    second->SetXSpeed(2 * firstSpeed * CosVminusPhi(firstVector, interaction) * interaction.x()
                + secondSpeed * SinVminusPhi(secondVector, interaction) * CosVplusPhi(interaction, piHalf));

    second->SetYSpeed(2 * firstSpeed * CosVminusPhi(firstVector, interaction) * interaction.y()
                + secondSpeed * SinVminusPhi(secondVector, interaction) * SinVplusPhi(interaction, piHalf));
}

void Physx::recalculateSpeeds(MovingChecker* first, MovingChecker* second)
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

    recalculateSpeedsOfMovingCheckers(first, second);
}

std::queue<Checker*> Physx::findAffectedCheckers(const MovingChecker& ch)
{
    std::queue<Checker*> affectedCheckers;
    for(Checker* checker : position->getCheckers())
    {
        if(!checker->getOutOfGame()
                && checker->getPosition().distanceToPoint(ch.GetChecker()->getPosition()) <= 2 * Checker::radius
                && checker->getPosition().distanceToPoint(ch.GetChecker()->getPosition()) > 0.001)
        {
                affectedCheckers.push(checker);
        }
    }

    return affectedCheckers;
}

void Physx::moveCheckersByOneStep()
{
    for(size_t i = 0; i < movingCheckers.size(); i++)
    {
        QVector2D speedDecreaser = movingCheckers[i].getSpeed().normalized() * (-speedDecrease);
        movingCheckers[i].makeStep();
        if(speedDecreaser.length() > movingCheckers[i].getSpeed().length())
        {
            movingCheckers[i].SetXSpeed(0);
            movingCheckers[i].SetYSpeed(0);
            continue;
        }
        if(fabs(speedDecreaser.x()) > fabs(movingCheckers[i].getSpeed().x()))
            speedDecreaser.setX(movingCheckers[i].getSpeed().x());
        if(fabs(speedDecreaser.y()) > fabs(movingCheckers[i].getSpeed().y()))
            speedDecreaser.setY(movingCheckers[i].getSpeed().y());

        movingCheckers[i].IncreaseSpeed(speedDecreaser);
    }
}

void Physx::deleteNotMovingCheckers()
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

void Physx::performCheckersInteraction()
{
    for(size_t i = 0; i < movingCheckers.size(); i++)
    {
        std::queue<Checker*> affectedCheckers = findAffectedCheckers(movingCheckers[i]);
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
            if(!checkerIsMoving(*affectedCheckers.front()))
            {
                movingCheckers.push_back(MovingChecker(affectedCheckers.front()));
                recalculateSpeeds(&movingCheckers.at(i), &movingCheckers.back());
            } else
            {
                int num = FindCheckerInMovingCheckers(affectedCheckers.front());
                //TODO handle -1
                recalculateSpeeds(&movingCheckers.at(i), &movingCheckers.at(num));
            }
            affectedCheckers.pop();
        }
    }
}

Physx::~Physx()
{
    movingCheckers.~vector();
}
