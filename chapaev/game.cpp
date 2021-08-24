#include "game.h"
#include "math.h"
#include <iostream>

Game::Game()
{
    this->WhitesTurn = true;
    this->BlackPoints = 0;
    this->WhitePoints = 0;
    this->physx = new Physx();
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
    return physx->getCheckers();
}

Game::~Game()
{
    //delete position;
    delete physx;
}
