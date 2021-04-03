#ifndef GAMEDATALOADER_H
#define GAMEDATALOADER_H
#include <qvector2d.h>


class StartGameData
{
private:
    int BlackCheckersQuantity;
    int WhiteCheckersQuantity;
    QVector2D *BlackCheckersPos;
    QVector2D *WhiteCheckersPos;

    void loadGameData();

public:
    StartGameData();
    int GetBlackCheckersQuantity();
    int GetWhiteCheckersQuantity();

    QVector2D *GetWhiteCheckersPositions();
    QVector2D *GetBlackCheckersPositions();
    ~StartGameData();

};

#endif // GAMEDATALOADER_H
