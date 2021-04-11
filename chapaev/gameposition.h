#ifndef GAMEPOSITION_H
#define GAMEPOSITION_H
#include <vector>
#include <checker.h>
#include "startgamedata.h"

class GamePosition
{
private:
    std::vector<Checker*> Checkers;
public:
    GamePosition();
    void ResetGamePosition();
    std::vector<Checker*> GetCheckers();
    ~GamePosition();
};

#endif // GAMEPOSITION_H
