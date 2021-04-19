#ifndef CHECKER_H
#define CHECKER_H

#include <QObject>
#include <QVector2D>

class Checker
{
private:
    QVector2D position;
    bool isOutOfGame;

public:
    static float radius;

    explicit Checker();
    QVector2D GetPosition();
    void SetPosition(QVector2D position);
    void SetOutOfGame (bool t);
    void IncrementPosition(float x, float y);
    bool GetOutOfGame();
    Checker(Checker& checker);

signals:

};

#endif // CHECKER_H
