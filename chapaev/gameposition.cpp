#include "gameposition.h"


GamePosition::GamePosition()
{
    GamePosition::ResetGamePosition();
}


void GamePosition::ResetGamePosition()
{
    unsigned int checkersNumber = InitGameData::GetInstance()->GetCheckersQuantity();
    unsigned int bCheckersNumber = InitGameData::GetInstance()->GetBlackCheckersQuantity();
    unsigned int wCheckersNumber = InitGameData::GetInstance()->GetWhiteCheckersQuantity();

    // Задаем нужное количество
    if(checkers.size() != checkersNumber)
        checkers.resize(checkersNumber);

    // Заполнение начальной информации шашек
    for(unsigned int i = 0; i < wCheckersNumber; i++)
    {
        if(checkers[i] == nullptr)
            checkers[i] = new Checker();
        checkers[i]->SetPosition(InitGameData::GetInstance()->GetWhiteCheckersPositions()[i]);
    }

    // Заполнение начальной информации шашек
    for(unsigned int i = 0; i < bCheckersNumber; i++)
    {
        if(checkers[i + wCheckersNumber] == nullptr)
            checkers[i + wCheckersNumber] = new Checker();
        checkers[i + wCheckersNumber]->SetPosition(InitGameData::GetInstance()->GetBlackCheckersPositions()[i]);
    }
}

std::vector<Checker *> GamePosition::GetCheckers()
{
    return checkers;
}

GamePosition::~GamePosition()
{
    this->checkers.clear();
}

