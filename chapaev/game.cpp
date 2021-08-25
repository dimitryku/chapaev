#include "game.h"
#include "math.h"
#include <iostream>

Game::Game()
{
    this->WhitesTurn = true;
    this->BlackPoints = 0;
    this->WhitePoints = 0;
    position = new GamePosition();
    this->physx = new Physx(position);
}

void Game::InitGameData()
{
    this->WhitesTurn = true;
    this->BlackPoints = 0;
    this->WhitePoints = 0;
}

bool Game::IsWhitesTurn(){ return WhitesTurn; }

void Game::ChangeTurn(){ WhitesTurn = !WhitesTurn; }

std::vector<Checker*>& Game::getGamePosition()
{
    return position->getCheckers();
}

Game::~Game()
{
    delete position;
    delete physx;
}
