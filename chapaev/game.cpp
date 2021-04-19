#include "game.h"
#include "math.h"
#include <iostream>

Game::Game()
{
    this->WhitesTurn = true;
    this->BlackPoints = 0;
    this->WhitePoints = 0;
    this->position = new GamePosition();
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

GamePosition* Game::GetGamePosition()
{
    return position;
}

Game::~Game()
{
    delete position;
    delete physx;
}
