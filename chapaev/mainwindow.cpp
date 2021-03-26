#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QtGui"
#include <QMessageBox>
#include "gameposition.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->setFixedHeight(XsceneSize);
    this->setFixedWidth(YsceneSize);
    ui->setupUi(this);
    //ui->graphicsView->setFixedSize(playgroundSize, playgroundSize);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_NewGameButton_clicked()
{
    QMessageBox *mb = new QMessageBox("Внимание!", "Начать новую игру? Прогресс будет потерян!", QMessageBox::Information, QMessageBox::Yes,
                                      QMessageBox::No, 0);
    int reply = mb->exec();
    delete mb;
    if(reply == QMessageBox::Yes)
    {
        //TODO restart game
        ui->statusBar->showMessage("Игра сброшена");
    }
}
