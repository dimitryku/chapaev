#include "gameposition.h"


GamePosition::GamePosition()
{
    GamePosition::ResetGamePosition();
}


void GamePosition::ResetGamePosition()
{
    StartGameData * data = new StartGameData();
    unsigned int checkersNumber = data->GetCheckersQuantity();

    // Задаем нужное количество белых
    if(checkers.size() != checkersNumber)
        checkers.resize(checkersNumber);

    // Заполнение начальной информации шашек
    for(unsigned int i = 0; i < checkersNumber; i++)
    {
        if(checkers[i] == nullptr)
            checkers[i] = new Checker();
        checkers[i]->SetPosition(data->GetWhiteCheckersPositions()[i]);
        // TODO: добавить создание вьюх
    }

    // Заполнение начальной информации шашек
    for(unsigned int i = 0; i < checkersNumber; i++)
    {
        if(checkers[i] == nullptr)
            checkers[i] = new Checker();
        checkers[i]->SetPosition(data->GetBlackCheckersPositions()[i]);
        // TODO: добавить создание вьюх
    }
    delete data;

}

std::vector<Checker *> GamePosition::GetCheckers()
{
    return checkers;
}

GamePosition::~GamePosition()
{
    this->checkers.clear();
}

