#include "gameview.h"

#include "iostream"

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

    //добавляем классы графического изображения действий
    checkerBounder = new ActiveCheckerBounder(checkersHolder->GetCheckers()[0]);
    dragStarted = false;
    inputLine = new InputLine();
}

void GameView::UpdatePositions(std::vector<Checker *> checkers)
{
//    for(Checker* ch : checkers)
//    {
//        QChecker* updatedCh = checkersHolder->GetConnectedQChecker(ch);
//        updatedCh->update();
//    }
    //this->viewport()->update();
    this->viewport()->repaint();
    //scene->update();
}

void GameView::DragStarted(QChecker *checker, QPointF pos)
{
    if(game->ManipulationAccepted(checker->GetBatleSide()))
    {
        //TODO fix line
        setMouseTracking(true);
        inputLine->SetStartPoint(pos);
        scene->addItem(inputLine);
        dragStarted = true;
        checkerBounder->AddBoundingCircle(checker);
        scene->addItem(checkerBounder);
    }
}

void GameView::DragFinished(QChecker *qchecker, QVector2D diff)
{
    if(dragStarted)
    {
        scene->removeItem(inputLine);
        scene->removeItem(checkerBounder);
        game->StartMovement(qchecker->GetChecker(), diff);
        dragStarted = false;
        std::cout << diff.x() << " " << diff.y() << std::endl;
    }
}

//TODO: change
void GameView::SetCheckers(Game* game, int num)
{
    checkersHolder = new QCheckersHolder(game);
    for(size_t i = 0; i < checkersHolder->GetCheckers().size(); i++)
    {
        //int r = Checker::radius;
        //int x = checkersHolder->GetCheckers()[i]->GetChecker()->GetPosition().x();
        //int y = checkersHolder->GetCheckers()[i]->GetChecker()->GetPosition().y();
        scene->addItem(checkersHolder->GetCheckers()[i]);
    }
}

void GameView::mouseMoveEvent(QMouseEvent *event)
{
    if(dragStarted)
    {
        QPointF pos = event->pos();
        //scene->
        inputLine->SetMousePos(pos);
    }
}
