#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <gameview.h>
#include "game.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void SetGame(Game* game);
    GameView *GetView();
    ~MainWindow();

private slots:
    void on_NewGameButton_clicked();

private:
    GameView* view;
    Game* game;
    Ui::MainWindow *ui;
//    int XsceneSize = 700; // Полный размер сцены по оси х
//    int YsceneSize = 700;  // Полный размер сцены по оси у
//    int playgroundSize = 500; // Размер игрового поля
};

#endif // MAINWINDOW_H
