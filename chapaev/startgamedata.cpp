#include "startgamedata.h"

StartGameData::StartGameData()
{
    //TODO dinamic setting
    BlackCheckersQuantity = 10;
    WhiteCheckersQuantity = 10;
    BlackCheckersPos = new QVector2D[BlackCheckersQuantity];
    WhiteCheckersPos = new QVector2D[WhiteCheckersQuantity];
}

int StartGameData::GetBlackCheckersQuantity(){ return BlackCheckersQuantity; }
int StartGameData::GetWhiteCheckersQuantity(){return WhiteCheckersQuantity;}
QVector2D * StartGameData::GetWhiteCheckersPositions(){return WhiteCheckersPos;}
QVector2D * StartGameData::GetBlackCheckersPositions(){return BlackCheckersPos;}
