#include "initgamedata.h"

InitGameData* InitGameData::instance = 0;

InitGameData* InitGameData::GetInstance()
{
    if(!instance)
        instance = new InitGameData();
    return instance;
}

InitGameData::InitGameData()
{
    // TODO: заменить временное на постоянное, динамическое
    blackCheckersQuantity = 8;
    whiteCheckersQuantity = 8;
    blackCheckersPos = new QVector2D[blackCheckersQuantity];
    whiteCheckersPos = new QVector2D[whiteCheckersQuantity];

    for(int i = 0; i < blackCheckersQuantity; i++)
    {
        blackCheckersPos[i].setX(i * GameView::rectSize);
        blackCheckersPos[i].setY(0);
        //std::cout << "bc " << blackCheckersPos[i].x() << " " << blackCheckersPos[i].y() << std::endl;
    }

    for(int i = 0; i < whiteCheckersQuantity; i++)
    {
        whiteCheckersPos[i].setX(blackCheckersPos[i].x());
        whiteCheckersPos[i].setY(blackCheckersPos[i].y() + 7 * GameView::rectSize);
        //std::cout << "wc " << whiteCheckersPos[i].x() << " " << whiteCheckersPos[i].y() << std::endl;
    }

}

int InitGameData::GetCheckersQuantity(){ return blackCheckersQuantity + whiteCheckersQuantity; }

int InitGameData::GetBlackCheckersQuantity()
{
    return blackCheckersQuantity;
}

int InitGameData::GetWhiteCheckersQuantity()
{
    return whiteCheckersQuantity;
}

QVector2D * InitGameData::GetWhiteCheckersPositions(){ return whiteCheckersPos; }

QVector2D * InitGameData::GetBlackCheckersPositions(){ return blackCheckersPos; }


InitGameData::~InitGameData()
{

    delete blackCheckersPos;
    delete whiteCheckersPos;
}
