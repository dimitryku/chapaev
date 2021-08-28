#include "gameview.h"

float GameView::rectSize = Checker::radius * 2 + 20;

GameView::GameView(Game* game, QObject *parent) : QGraphicsView()
{
    this->game = game;
    scene = new QGraphicsScene();
    this->setScene(scene);

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

    //создаем шашки
    SetCheckers(game, 8);
    //соединяем сигналы и слоты
    for(QChecker* ch : checkersHolder->GetCheckers())
    {
        connect(ch, SIGNAL(Pressed(QChecker*, QPointF)), this, SLOT(DragStarted(QChecker*, QPointF)));
        connect(ch, SIGNAL(Released(QChecker*, QVector2D)), this, SLOT(DragFinished(QChecker*, QVector2D)));
    }
}

void GameView::DragStarted(QChecker *checker, QPointF pos)
{
    if(game->ManipulationAccepted(checker->GetBatleSide()))
    {
        //TODO draw line and circle
    }
}

void GameView::DragFinished(QChecker *qchecker, QVector2D diff)
{
    //TODO remove line and circle
    game->StartMovement(qchecker->GetChecker(), diff);
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
    }
}

