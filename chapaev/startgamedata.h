#ifndef GAMEDATALOADER_H
#define GAMEDATALOADER_H
#include <qvector2d.h>


class StartGameData
{
private:
    static StartGameData * instance;
    int BlackCheckersQuantity;
    int WhiteCheckersQuantity;
    QVector2D *BlackCHeckersPos;
    QVector2D *WhiteCHeckersPos;

    void loadGameData();

public:
    static StartGameData *GetInstance();
    StartGameData();
    int GetBlackCheckersQuantity();
    int GetWhiteCheckersQuantity();

};

#endif // GAMEDATALOADER_H
