#include "gameview.h"

float GameView::rectSize = Checker::radius * 2 + 20;

GameView::GameView(QObject *parent, Game* game) : QGraphicsView()
{
    scene = new QGraphicsScene();
    this->setScene(scene);
    checkers = new QGraphicsItemGroup();
    scene->addItem(checkers);

    // создаем доску
    board = new QBoard(8, 8);
    scene->addItem(board);

    // настройка сцены
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setAlignment(Qt::AlignCenter);
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    this->setMinimumHeight(900);
    this->setMinimumWidth(900);
    scene->setBackgroundBrush(QBrush(Qt::gray, Qt::Dense5Pattern));

    //TODO создаем шашки
    SetCheckers(game, 8);
}

void GameView::SetCheckers(Game* game, int num)
{
    //float bound = (rectSize - 2*Checker::radius) / 2.0;
    checkersHolder = new QCheckersHolder(game);
    for(size_t i = 0; i < checkersHolder->GetCheckers().size(); i++)
    {
        //int r = Checker::radius;
        //int x = checkersHolder->GetCheckers()[i]->GetChecker()->GetPosition().x();
        //int y = checkersHolder->GetCheckers()[i]->GetChecker()->GetPosition().y();
        scene->addItem(checkersHolder->GetCheckers()[i]);
//        checkers->addToGroup(scene->addEllipse(x + bound, y + bound, 2*r, 2*r,
//                                               checkersHolder->GetCheckers()[i]->GetViewStyle()->pen,
//                                               checkersHolder->GetCheckers()[i]->GetViewStyle()->brush));
    }
}

