#include "game.h"
#include "startgamedata.h"

Game::Game()
{


}

void Game::InitGameData()
{
    WhitesTurn = true;

}

bool Game::IsWhitesTurn(){ return WhitesTurn; }
