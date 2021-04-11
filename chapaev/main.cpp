#include "mainwindow.h"
#include <QApplication>
#include "iostream"
#include "game.h"

int main(int argc, char *argv[])
{
    // game check
    Game* game = new Game();
    game->physx->PerformMoves(MovingChecker(game->GetGamePosition()->GetCheckers().at(0), 7, 7));
    std::cout << "positions: " << std::endl;
    for(Checker* ch : game->GetGamePosition()->GetCheckers())
    {
        std::cout << ch->GetPosition().x() << " " << ch->GetPosition().y() << std::endl;
    }

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
