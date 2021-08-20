#include "qt/mainwindow.h"
#include <QApplication>
#include "iostream"
#include "game.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Game* game = new Game();
    MainWindow w(0, game);

    w.show();

    return a.exec();
}
