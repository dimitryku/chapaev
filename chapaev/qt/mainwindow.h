#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "gameview.h"
#include "game.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    GameView *GetView();
    ~MainWindow();

private slots:
    void on_NewGameButton_clicked();

private:
    Game* game;
    GameView* view;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
