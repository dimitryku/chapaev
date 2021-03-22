#include "startgamedata.h"

StartGameData::StartGameData()
{
    //TODO dinamic setting
    BlackCheckersQuantity = 10;
    WhiteCheckersQuantity = 10;
    BlackCHeckersPos = new QVector2D[BlackCheckersQuantity];
    WhiteCHeckersPos = new QVector2D[WhiteCheckersQuantity];
}

StartGameData *StartGameData::GetInstance()
{
    if (!instance)
    {
        instance = new StartGameData();
    }
    return instance;
}

int StartGameData::GetBlackCheckersQuantity(){ return BlackCheckersQuantity; }
int StartGameData::GetWhiteCheckersQuantity(){return WhiteCheckersQuantity;}
