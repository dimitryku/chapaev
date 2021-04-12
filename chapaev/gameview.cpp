#include "gameview.h"

GameView::GameView(QObject *parent) : QGraphicsView()
{
    scene = new QGraphicsScene();
    board = new QGraphicsItemGroup();
    checkers = new QGraphicsItemGroup();
    scene->addItem(board);
    scene->addItem(checkers);
    this->setScene(scene);

    // настройка сцены
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setAlignment(Qt::AlignCenter);
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    this->setMinimumHeight(900);
    this->setMinimumWidth(900);
    scene->setBackgroundBrush(QBrush(Qt::gray, Qt::Dense5Pattern));

    // создаем доску
    SetBoard(8);
    //TODO создаем шашки
}

void GameView::SetBoard(int num)
{
    int sz = 80;
    int Xindent = scene->width()/2.0 - sz*num/2.0;
    int Yindent = scene->height()/2.0 - sz*num/2.0;
    for(int i = 0; i < num; i++)
        for(int j = 0; j < num; j++)
        {
            if((i + j) % 2 == 1)
                board->addToGroup(scene->addRect(sz*i + Xindent, sz*j + Yindent, sz, sz, QPen(Qt::white), QBrush(QColor(119, 153, 82))));
            else
                board->addToGroup(scene->addRect(sz*i + Xindent, sz*j + Yindent, sz, sz, QPen(Qt::white), QBrush(QColor(255, 255, 231))));
        }

}
