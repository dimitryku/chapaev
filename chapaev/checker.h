#ifndef CHECKER_H
#define CHECKER_H

#include <QObject>
#include <QVector2D>

class Checker : public QObject
{
    Q_OBJECT
private:
    QVector2D position;
    bool isOutOfGame;

public:
    explicit Checker(QObject *parent = nullptr);
    QVector2D GetPosition();
    void SetPosition(QVector2D position);
    void SetOutOfGame (bool t);
    bool GetOutOfGame();

signals:

};

#endif // CHECKER_H
