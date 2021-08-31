#ifndef QCHECKERHOLDER_H
#define QCHECKERHOLDER_H

#include "qt/qchecker.h"
#include "initgamedata.h"
#include "game.h"

class Game;

class QCheckersHolder
{
private:
    std::vector<QChecker*> checkers;
public:
    explicit QCheckersHolder(Game* game);
    std::vector<QChecker*>& GetCheckers();
    QChecker *GetConnectedQChecker(Checker* checker);
};

#endif // QCHECKERHOLDER_H
