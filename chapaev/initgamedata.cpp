#include "initgamedata.h"
#include "qt/gameview.h"

static constexpr int blackCheckersQuantity = 8;
static constexpr int whiteCheckersQuantity = 8;

InitGameData* InitGameData::instance = nullptr;

InitGameData* InitGameData::GetInstance()
{
    if(!instance)
        instance = new InitGameData();
    return instance;
}

InitGameData::InitGameData()
{
    blackCheckersPositions.resize(blackCheckersQuantity);
    whiteCheckersPositions.resize(whiteCheckersQuantity);

    for(int i = 0; i < blackCheckersQuantity; i++)
    {
        blackCheckersPositions[i].setX(i * GameView::rectSize + GameView::rectSize / 2);
        blackCheckersPositions[i].setY(GameView::rectSize / 2);
    }

    for(int i = 0; i < whiteCheckersQuantity; i++)
    {
        whiteCheckersPositions[i].setX(blackCheckersPositions[i].x());
        whiteCheckersPositions[i].setY(blackCheckersPositions[i].y() + 7 * GameView::rectSize);
    }

}

int InitGameData::GetCheckersQuantity(){ return whiteCheckersPositions.size() + blackCheckersPositions.size(); }

int InitGameData::GetBlackCheckersQuantity() { return blackCheckersPositions.size(); }

int InitGameData::GetWhiteCheckersQuantity() { return whiteCheckersPositions.size(); }
