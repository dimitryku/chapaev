#ifndef GAME_H
#define GAME_H


class Game
{
private:
    int WhitePoints;
    int BlackPoints;


public:
    Game();
    void InitGameData();
    void ResetGame();
};

#endif // GAME_H
