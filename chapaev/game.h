#ifndef GAME_H
#define GAME_H


class Game
{
private:
    int WhitePoints;
    int BlackPoints;
    bool WhitesTurn;


public:
    Game();
    void InitGameData();
    bool IsWhitesTurn();
    void ChangeTurn();
};

#endif // GAME_H