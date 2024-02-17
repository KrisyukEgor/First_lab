#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPalette>
#include <QPainter>
#include <QGraphicsScene>




QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Sail_up_clicked();
    void on_Sail_down_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene* scene;



protected:
    void paintEvent(QPaintEvent*) override;

};

#endif // MAINWINDOW_H