#include "game.h"
#include "math.h"
#include <iostream>

Game::Game()
{
    WhitesTurn = true;
    BlackPoints = 0;
    WhitePoints = 0;
    position = new GamePosition();
    physx = new Physx(position);
}

void Game::InitGameData()
{
    WhitesTurn = true;
    BlackPoints = 0;
    WhitePoints = 0;
}

bool Game::IsWhitesTurn(){ return WhitesTurn; }

void Game::ChangeTurn(){ WhitesTurn = !WhitesTurn; }

GamePosition *Game::GetGamePosition()
{
    return position;
}

Game::~Game()
{
    delete position;
}
