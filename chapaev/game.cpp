#include "game.h"
#include "math.h"
#include <iostream>

Game::Game()
{
    this->currentSide = BattleSide::white;
    this->blackPoints = 0;
    this->whitePoints = 0;
    position = new GamePosition();
    this->physx = new Physx(position);
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
    //TODO: implement
}

Game::~Game()
{
    delete position;
    delete physx;
}
