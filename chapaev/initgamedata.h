#ifndef GAMEDATALOADER_H
#define GAMEDATALOADER_H
#include <QVector2D>

#include "qt/qchecker.h"
#include "qt/checkerviewstyle.h"

class Game;

class InitGameData
{
private:
    static InitGameData* instance;

    QVector<QVector2D> blackCheckersPositions;
    QVector<QVector2D> whiteCheckersPositions;
    void loadGameData();

public:
    static InitGameData* GetInstance();
    InitGameData();
    int GetCheckersQuantity();
    int GetBlackCheckersQuantity();
    int GetWhiteCheckersQuantity();
    const QVector<QVector2D>& GetWhiteCheckersPositions() const { return whiteCheckersPositions; }
    const QVector<QVector2D>& GetBlackCheckersPositions() const { return blackCheckersPositions; }
    void InitQCheckers(std::vector<QChecker>* checkers, Game* game);

};

#endif // GAMEDATALOADER_H
