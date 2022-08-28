#ifndef CHECKER_H
#define CHECKER_H

#include <QVector2D>

class Checker
{
public:
    static float radius;

    Checker();
    Checker(const Checker& checker);

    QVector2D getPosition() const;
    void setPosition(const QVector2D& position);
    void setOutOfGame (bool value = true);
    void incrementPosition(const QVector2D& delta);
    bool getOutOfGame() const;

private:
    QVector2D position;
    bool isOutOfGame;
};

#endif // CHECKER_H
