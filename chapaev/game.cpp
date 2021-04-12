#include "game.h"
#include "math.h"
#include <iostream>

Game::Game(GameView *v)
{
    WhitesTurn = true;
    BlackPoints = 0;
    WhitePoints = 0;
    position = new GamePosition();
    physx = new Physx(position);
    view = v;
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
