#ifndef QCHECKERHOLDER_H
#define QCHECKERHOLDER_H

#include "qt/qchecker.h"
#include <vector>
#include "initgamedata.h"
#include "game.h"

class Game;

class qCheckerHolder
{
private:
    std::vector<qChecker*> checkers;
public:
    explicit qCheckerHolder(Game* game);
    std::vector<qChecker*> GetCheckers() const;
};

#endif // QCHECKERHOLDER_H
