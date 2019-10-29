#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowFlags(Qt::Window|Qt::FramelessWindowHint|Qt::Tool|Qt::FramelessWindowHint |Qt::WindowStaysOnTopHint);
    setAttribute(Qt::WA_TranslucentBackground);
    gl = new QtSGLWidget(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



