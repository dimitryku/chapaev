#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>

#include "gameposition.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , game(new Game())
    , view(new GameView(game))
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //TODO: check, mb change later
    game->SetView(view);

    ui->gridLayout->addWidget(view);
}

void MainWindow::on_NewGameButton_clicked()
{
    QMessageBox mb("Внимание!", "Начать новую игру? Прогресс будет потерян!",
                    QMessageBox::Information,
                    QMessageBox::Yes, QMessageBox::No, 0);
    int reply = mb.exec();
    if(reply == QMessageBox::Yes)
    {
        //TODO restart game
        ui->statusBar->showMessage("Игра сброшена");
    }
}

GameView *MainWindow::GetView()
{
    return view;
}

MainWindow::~MainWindow()
{
    delete view;
    delete ui;
}
