#include <QtWidgets>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    createMenu();
}

void MainWindow::createMenu()
{
//  FILE MENU
    QMenu *fileMenu = menuBar()->addMenu(tr("&File"));
//  OPEN ACTION
    QAction *openAct = new QAction(tr("&Open"), this);
    openAct->setShortcuts(QKeySequence::Open);
    openAct->setStatusTip(tr("Open a file"));
    connect(openAct, &QAction::triggered, this, &MainWindow::open);
    fileMenu->addAction(openAct);
    fileMenu->addSeparator();

//  EDIT MENU
    QMenu *editMenu = menuBar()->addMenu(tr("&Edit"));
    editMenu->addSeparator();

//  HELP MENU
    QMenu *helpMenu = menuBar()->addMenu(tr("&Help"));
    helpMenu->addSeparator();
}

void MainWindow::open()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("JPEG (*.jpg *.jpeg);;PNG (*.png)" ));
    imageObject = new QImage();
    imageObject->load(fileName);
    image = QPixmap::fromImage(*imageObject);
    scene = new QGraphicsScene(this);
    scene->addPixmap(image);
    scene->setSceneRect(image.rect());
//    ui->graphicsView->setScene(scene);
}

MainWindow::~MainWindow()
{
    delete ui;
}
