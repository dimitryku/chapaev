#ifndef GAMEPOSITION_H
#define GAMEPOSITION_H
#include <vector>
#include "checker.h"
#include "initgamedata.h"

class GamePosition
{
private:
    std::vector<Checker*> checkers;
public:
    GamePosition();
    void ResetGamePosition();
    std::vector<Checker*>& getCheckers();
    ~GamePosition();
};

#endif // GAMEPOSITION_H
