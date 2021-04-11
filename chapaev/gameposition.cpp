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
    if(Checkers.size() != checkersNumber)
        Checkers.resize(checkersNumber);

    // Заполнение начальной информации шашек
    for(unsigned int i = 0; i < checkersNumber; i++)
    {
        if(Checkers[i] == nullptr)
            Checkers[i] = new Checker();
        Checkers[i]->SetPosition(data->GetWhiteCheckersPositions()[i]);
        // TODO: добавить создание вьюх
    }

    // Заполнение начальной информации шашек
    for(unsigned int i = 0; i < checkersNumber; i++)
    {
        if(Checkers[i] == nullptr)
            Checkers[i] = new Checker();
        Checkers[i]->SetPosition(data->GetBlackCheckersPositions()[i]);
        // TODO: добавить создание вьюх
    }
    delete data;

}

std::vector<Checker *> GamePosition::GetCheckers()
{
    return Checkers;
}

GamePosition::~GamePosition()
{
    this->Checkers.clear();
}

