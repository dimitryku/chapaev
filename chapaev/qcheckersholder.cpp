#include "qcheckersholder.h"

QCheckersHolder::QCheckersHolder(Game* game)
{
    InitGameData* initer = InitGameData::GetInstance();
    CheckerViewStyle * stl = new CheckerViewStyle(BattleSide::black);
    int i;
    for(i = 0; i < initer->GetBlackCheckersQuantity(); i++)
    {
        checkers.push_back(new QChecker(game->GetGamePosition()[i],
                                         stl, BattleSide::black));
    }
    stl = new CheckerViewStyle(BattleSide::white);
    for(int j = i; j < i + initer->GetWhiteCheckersQuantity(); j++)
    {
        checkers.push_back(new QChecker(game->GetGamePosition()[j],
                                         stl, BattleSide::white));
    }
    delete initer;
}

std::vector<QChecker*>& QCheckersHolder::GetCheckers()
{
    return checkers;
}
