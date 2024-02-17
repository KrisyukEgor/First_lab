#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include "board.h"


Boat* boat = new Boat();


MainWindow::MainWindow(QWidget *parent)  : QMainWindow(parent) , ui(new Ui::MainWindow){
    ui->setupUi(this);
    scene = new QGraphicsScene();
    ui -> graphicsView -> setScene(scene);
    scene -> addItem(boat);
    scene -> addItem(boat -> Rect_1);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Sail_down_clicked()
{

    ui -> Sail_up -> setEnabled(false);
    ui -> Sail_down -> setText("Парус опускается");

    if(boat -> Rect_1 -> y() >= 0 && boat -> Rect_1 -> y() <= 60){
        ui -> Sail_down -> setEnabled(false);
        ui -> Sail_up -> setEnabled(false);
    }
    boat -> Move_Down();
    ui -> Sail_down -> setText("Парус опускается");
    QTimer* timer = new QTimer(this);
    int seconds = 2642;
    timer->setSingleShot(true);

    connect(timer, &QTimer::timeout, this, [=]() {
        ui -> Sail_down -> setText("Парус опустился");
        ui -> Sail_up -> setText("Поднять парус");
        ui -> Sail_up -> setEnabled(true);
        ui -> Sail_down -> setEnabled(false);

    });

    timer->start(seconds);

}

void MainWindow::paintEvent(QPaintEvent* event)
{
}

void MainWindow::on_Sail_up_clicked()
{
    ui -> Sail_down -> setEnabled(false);
    ui -> Sail_up -> setText("Парус поднялся");
    if(boat -> Rect_1 -> y() >= 0 && boat -> Rect_1 -> y() <= 120){
        ui -> Sail_down -> setEnabled(false);
        ui -> Sail_up -> setEnabled(false);
    }
    boat -> Move_Up();
    ui -> Sail_up -> setText("Парус поднимается");
    QTimer* timer = new QTimer(this);
    int seconds = 2642;
    timer->setSingleShot(true);

    connect(timer, &QTimer::timeout, this, [=]() {
        ui -> Sail_up -> setText("Парус поднялся");
        ui -> Sail_down -> setText("Опустить парус");
        ui -> Sail_down -> setEnabled(true);
        ui -> Sail_up -> setEnabled(false);

    });

    timer->start(seconds);


}



