#ifndef QCHECKERHOLDER_H
#define QCHECKERHOLDER_H

#include "qt/qchecker.h"
#include <vector>
#include "initgamedata.h"
#include "game.h"

class Game;

class QCheckersHolder
{
private:
    std::vector<QChecker*> checkers;
public:
    explicit QCheckersHolder(Game* game);
    std::vector<QChecker*> GetCheckers() const;
};

#endif // QCHECKERHOLDER_H
