#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <myscene.h>
#include <figureTypes.h>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    scene = new MyScene( this);


    ui->setupUi(this);
    scene = new MyScene();
    scene->setSceneRect(QRectF(0, 0, 5000, 5000));

  ui->graphicsView->setScene(scene);




    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);

    ui->graphicsView->setSceneRect(0,0,5000,5000);
    //ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
   // ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    ui->myRectButton->setDisabled(true);
    ui->mySaveButton->setDisabled(true);











}

MainWindow::~MainWindow()
{
    delete scene;
    delete ui;
}


void MainWindow::on_myCirclebutton_clicked()
{
    ui->myCirclebutton->setDown(true);
    ui->myLineButton->setDown(false);
    ui->myMoveButton->setDown(false);

  scene->setFigureType(myCircle);

}

void MainWindow::on_clearButton_clicked()
{
    scene->clear();
    scene->update();
}


void MainWindow::on_myLineButton_clicked()
{
    ui->myCirclebutton->setDown(false);
    ui->myLineButton->setDown(true);
    ui->myMoveButton->setDown(false);


 scene->setFigureType(myLine);


}

void MainWindow::on_myMoveButton_clicked()
{
    ui->myCirclebutton->setDown(false);
    ui->myLineButton->setDown(false);
    ui->myMoveButton->setDown(true);


   scene->setFigureType(myMove);

}

void MainWindow::on_myExitButton_clicked()
{
    exit(0);
}
