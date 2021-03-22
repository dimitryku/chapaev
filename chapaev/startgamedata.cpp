#include "startgamedata.h"

StartGameData::StartGameData()
{
    BlackCheckersQuantity = 10;

    BlackCHeckersPos = new QVector2D[BlackCheckersQuantity];
    WhiteCHeckersPos = new QVector2D[WhiteCheckersQuantity];
}

StartGameData *StartGameData::GetInstance()
{
//    if (!instance)
//    {
//        instance = new StartGameData();
//    }
//    return instance;
}

int GetBlackCheckersQuantity(){return 0;}
int GetWhiteCheckersQuantity(){return 0;}
