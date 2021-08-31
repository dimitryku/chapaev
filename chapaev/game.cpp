#include "game.h"

Game::Game()
{
    this->currentSide = BattleSide::white;
    this->blackPoints = 0;
    this->whitePoints = 0;
    position = new GamePosition();
    this->physx = new Physx(position);
    interfaceIsActive = true;

    timer = new QTimer(this);
    timer->setInterval(10);
    connect(timer, SIGNAL(timeout()), this, SLOT(MakeStep()));
}

void Game::ChangeTurn()
{
    switch (currentSide) {
    case BattleSide::white:
        currentSide = BattleSide::black;
        break;
    case BattleSide::black:
        currentSide = BattleSide::white;
    default:
        break;
    }
}

std::vector<Checker*>& Game::GetGamePosition()
{
    return position->getCheckers();
}

void Game::SetView(GameView *view)
{
    this->view = view;
}

bool Game::ManipulationAccepted(BattleSide side)
{
    return (interfaceIsActive && side == currentSide);
}

void Game::StartMovement(Checker *checker, QVector2D moveInput)
{
    interfaceIsActive = false;
    //TODO: change speed
    physx->PrepareData(checker, moveInput*0.1);
    //TODO: start timer
    timer->start();
}

void Game::MakeStep()
{
    //TODO: implement
    std::vector<Checker*> affectedCheckers = physx->MakeStep();
    if(!affectedCheckers.empty())
    {
        view->UpdatePositions(affectedCheckers);
    }
    else
    {
        FinishMovement();
    }
}

void Game::FinishMovement()
{
    timer->stop();
    interfaceIsActive = true;
}

Game::~Game()
{
    delete position;
    delete physx;
}
