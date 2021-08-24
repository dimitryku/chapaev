#include "qcheckerholder.h"

qCheckerHolder::qCheckerHolder(Game* game)
{
    InitGameData* initer = InitGameData::GetInstance();
    CheckerViewStyle * stl = new CheckerViewStyle(BattleSide::black);
    int i;
    for(i = 0; i < initer->GetBlackCheckersQuantity(); i++)
    {
        checkers.push_back(new qChecker(game->getGamePosition()[i],
                                         stl, BattleSide::black));
    }
    stl = new CheckerViewStyle(BattleSide::white);
    for(int j = i; j < i + initer->GetWhiteCheckersQuantity(); j++)
    {
        checkers.push_back(new qChecker(game->getGamePosition()[j],
                                         stl, BattleSide::white));
    }
}

std::vector<qChecker*> qCheckerHolder::GetCheckers() const
{
    return checkers;
}
