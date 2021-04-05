#include "startgamedata.h"

StartGameData::StartGameData()
{
    // TODO: заменить временное на постоянное, динамическое
    BlackCheckersQuantity = 4;
    WhiteCheckersQuantity = 0;
    BlackCheckersPos = new QVector2D[BlackCheckersQuantity];
    WhiteCheckersPos = new QVector2D[WhiteCheckersQuantity];

    for(int i = 0; i < BlackCheckersQuantity; i++)
    {
        BlackCheckersPos[i].setX(i * 20);
        BlackCheckersPos[i].setY(i * 20);
    }
}

int StartGameData::GetBlackCheckersQuantity(){ return BlackCheckersQuantity; }

int StartGameData::GetWhiteCheckersQuantity(){ return WhiteCheckersQuantity; }

QVector2D * StartGameData::GetWhiteCheckersPositions(){ return WhiteCheckersPos; }

QVector2D * StartGameData::GetBlackCheckersPositions(){ return BlackCheckersPos; }

StartGameData::~StartGameData()
{
    delete BlackCheckersPos;
    delete WhiteCheckersPos;
}
