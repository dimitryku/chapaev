#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QtGui"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //ui->resize(YsceneSize, XsceneSize);
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QMessageBox *mb = new QMessageBox("Внимание!", "Начать новую игру? Прогресс будет потерян!", QMessageBox::Information, QMessageBox::Yes,
                                      QMessageBox::No,
                                      QMessageBox::Cancel | QMessageBox::Escape);
    int reply = mb->exec();
    delete mb;
    if(reply == QMessageBox::Yes)
    {
        //TODO restart game
        ui->statusBar->showMessage("Игра сброшена");
    }
}
