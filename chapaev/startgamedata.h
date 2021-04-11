#ifndef GAMEDATALOADER_H
#define GAMEDATALOADER_H
#include <qvector2d.h>


class StartGameData
{
private:
    int blackCheckersQuantity;
    int whiteCheckersQuantity;
    QVector2D *BlackCheckersPos;
    QVector2D *WhiteCheckersPos;

    void loadGameData();

public:
    StartGameData();
    int GetCheckersQuantity();
    QVector2D *GetWhiteCheckersPositions();
    QVector2D *GetBlackCheckersPositions();
    ~StartGameData();

};

#endif // GAMEDATALOADER_H
