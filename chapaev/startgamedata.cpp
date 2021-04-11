#include "startgamedata.h"

StartGameData::StartGameData()
{
    // TODO: заменить временное на постоянное, динамическое
    blackCheckersQuantity = 4;
    whiteCheckersQuantity = 0;
    BlackCheckersPos = new QVector2D[blackCheckersQuantity];
    WhiteCheckersPos = new QVector2D[whiteCheckersQuantity];

    for(int i = 0; i < blackCheckersQuantity; i++)
    {
        BlackCheckersPos[i].setX(i * 20);
        BlackCheckersPos[i].setY(i * 20);
    }
}

int StartGameData::GetCheckersQuantity(){ return blackCheckersQuantity + whiteCheckersQuantity; }

QVector2D * StartGameData::GetWhiteCheckersPositions(){ return WhiteCheckersPos; }

QVector2D * StartGameData::GetBlackCheckersPositions(){ return BlackCheckersPos; }

StartGameData::~StartGameData()
{

    delete BlackCheckersPos;
    delete WhiteCheckersPos;
}
