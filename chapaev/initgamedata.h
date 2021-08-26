#ifndef GAMEDATALOADER_H
#define GAMEDATALOADER_H
#include <qvector2d.h>
#include <vector>
#include "qt/qchecker.h"
#include "qt/checkerviewstyle.h"
#include "BattleSide.h"
#include "game.h"
#include <iostream>

class Game;

class InitGameData
{
private:
    static InitGameData* instance;

    int blackCheckersQuantity;
    int whiteCheckersQuantity;
    QVector2D *blackCheckersPos;
    QVector2D *whiteCheckersPos;
    void loadGameData();

public:
    static InitGameData* GetInstance();
    InitGameData();
    int GetCheckersQuantity();
    int GetBlackCheckersQuantity();
    int GetWhiteCheckersQuantity();
    QVector2D *GetWhiteCheckersPositions();
    QVector2D *GetBlackCheckersPositions();
    void InitQCheckers(std::vector<QChecker>* checkers, Game* game);
    ~InitGameData();

};

#endif // GAMEDATALOADER_H
