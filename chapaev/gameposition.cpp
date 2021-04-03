#include "gameposition.h"


GamePosition::GamePosition()
{
    GamePosition::ResetGamePosition();
}


void GamePosition::ResetGamePosition()
{
    StartGameData * data = new StartGameData();
    unsigned int checkersNumber = data->GetWhiteCheckersQuantity();

    // Задаем нужное количество белых шашек
    if(WhiteCheckers.size() != checkersNumber)
        WhiteCheckers.resize(checkersNumber);

    //Заполнение начальной информации шашек
    for(unsigned int i = 0; i < checkersNumber; i++)
    {
        if(WhiteCheckers[i] == nullptr)
            WhiteCheckers[i] = new Checker();
        WhiteCheckers[i]->SetPosition(data->GetWhiteCheckersPositions()[i]);
        // TODO: добавить по необходимости
    }

    checkersNumber = data->GetBlackCheckersQuantity();

    // Задаем нужное количество белых шашек
    if(BlackCheckers.size() != checkersNumber)
        BlackCheckers.resize(checkersNumber);

    //Заполнение начальной информации шашек
    for(unsigned int i = 0; i < checkersNumber; i++)
    {
        if(BlackCheckers[i] == nullptr)
            BlackCheckers[i] = new Checker();
        BlackCheckers[i]->SetPosition(data->GetBlackCheckersPositions()[i]);
        // TODO: добавить по необходимости
    }
    delete data;

}

std::vector<Checker *> GamePosition::GetWhiteCheckers()
{
    return WhiteCheckers;
}

std::vector<Checker *> GamePosition::GetBlackCheckers()
{
    return BlackCheckers;
}

