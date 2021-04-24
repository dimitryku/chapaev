#include "gameview.h"

float GameView::rectSize = Checker::radius * 2 + 20;

GameView::GameView(QObject *parent, Game* game) : QGraphicsView()
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
    SetCheckers(game, 8);
}

void GameView::SetCheckers(Game* game, int num)
{
    //float bound = (rectSize - 2*Checker::radius) / 2.0;
    checkersHolder = new qCheckerHolder(game);
    for(int i = 0; i < checkersHolder->GetCheckers().size(); i++)
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

void GameView::SetBoard(int num)
{
    for(int i = 0; i < num; i++)
        for(int j = 0; j < num; j++)
            {
                if((i + j) % 2 == 1)
                    board->addToGroup(scene->addRect(rectSize*i, rectSize*j, rectSize, rectSize, QPen(Qt::white), QBrush(QColor(119, 153, 82))));
                else
                    board->addToGroup(scene->addRect(rectSize*i, rectSize*j, rectSize, rectSize, QPen(Qt::white), QBrush(QColor(255, 255, 231))));
            }


}
