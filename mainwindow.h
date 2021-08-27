#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <myscene.h>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public:
    Ui::MainWindow *ui;
    MyScene *scene=nullptr;
    QGraphicsView *view;




private slots:
    void on_myCirclebutton_clicked();
    void on_clearButton_clicked();

    void on_myLineButton_clicked();
    void on_myMoveButton_clicked();
    void on_myExitButton_clicked();
};
#endif // MAINWINDOW_H
