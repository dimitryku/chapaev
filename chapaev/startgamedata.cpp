#include "startgamedata.h"

StartGameData::StartGameData()
{
    //TODO dinamic setting
    BlackCheckersQuantity = 5;
    WhiteCheckersQuantity = 0;
    BlackCheckersPos = new QVector2D[BlackCheckersQuantity];
    WhiteCheckersPos = new QVector2D[WhiteCheckersQuantity];
    for(int i = 0; i < BlackCheckersQuantity; i++)
    {
        BlackCheckersPos[i].setX(i*10);
        BlackCheckersPos[i].setY(i*10);
    }
}

int StartGameData::GetBlackCheckersQuantity(){ return BlackCheckersQuantity; }
int StartGameData::GetWhiteCheckersQuantity(){return WhiteCheckersQuantity;}
QVector2D * StartGameData::GetWhiteCheckersPositions(){return WhiteCheckersPos;}
QVector2D * StartGameData::GetBlackCheckersPositions(){return BlackCheckersPos;}
