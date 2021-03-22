#include "gameposition.h"


GamePosition::GamePosition()
{
    BlackCheckers = new Checker[StartGameData::GetInstance()->GetBlackCheckersQuantity()];
    WhiteCheckers = new Checker[StartGameData::GetInstance()->GetWhiteCheckersQuantity()];
}
