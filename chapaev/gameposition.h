#ifndef GAMEPOSITION_H
#define GAMEPOSITION_H
#include <vector>
#include <checker.h>
#include "startgamedata.h"

class GamePosition
{
private:
    std::vector<Checker*> WhiteCheckers;
    std::vector<Checker*> BlackCheckers;
public:
    GamePosition();
    void ResetGamePosition();
    std::vector<Checker*> GetWhiteCheckers();
    std::vector<Checker*> GetBlackCheckers();

};

#endif // GAMEPOSITION_H
