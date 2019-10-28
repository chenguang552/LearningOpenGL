#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    setWindowTitle("山寨宠物");
//    QMovie *MyPetMovie = new QMovie(":/timg.gif");
//    ui->graphicsView->setMovie(MyPetMovie);

    setWindowFlags(Qt::Window|Qt::FramelessWindowHint|Qt::Tool|Qt::FramelessWindowHint |Qt::WindowStaysOnTopHint);
    setAttribute(Qt::WA_TranslucentBackground);
//    setWindowFlags(Qt::FramelessWindowHint |Qt::WindowStaysOnTopHint);
//    MyPetMovie->start();

    gl = new QtSGLWidget(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



