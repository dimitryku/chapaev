#ifndef CHECKER_H
#define CHECKER_H

#include <QObject>
#include <QVector2D>

class Checker : public QObject
{
    Q_OBJECT
private:
    QVector2D position;
public:
    explicit Checker(QObject *parent = nullptr);
    QVector2D GetPosition();

signals:

};

#endif // CHECKER_H
