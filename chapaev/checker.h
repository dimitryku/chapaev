#ifndef CHECKER_H
#define CHECKER_H

#include <QObject>
#include <QVector2D>

class Checker
{
private:
    QVector2D position;
    bool isOutOfGame;
    float radius;

public:
    explicit Checker();
    QVector2D GetPosition();
    void SetPosition(QVector2D position);
    void SetOutOfGame (bool t);
    void IncrementPosition(float x, float y);
    bool GetOutOfGame();
    void SetRadius(float radius);
    float GetRadius();
    Checker(Checker& checker);

signals:

};

#endif // CHECKER_H
