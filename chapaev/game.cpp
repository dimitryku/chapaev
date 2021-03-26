#include "game.h"
#include "startgamedata.h"

Game::Game()
{
    InitGameData();
}

void Game::InitGameData()
{
    WhitesTurn = true;
    BlackPoints = 0;
    WhitePoints = 0;
}

bool Game::IsWhitesTurn(){ return WhitesTurn; }

void Game::ChangeTurn(){ WhitesTurn = !WhitesTurn; }
