#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_gameTable = new GameTable(m_squareSize);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
    ui->graphicsView->setScene(m_gameTable);
    ui->graphicsView->showMaximized();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    if (ui->graphicsView->size().height()>ui->graphicsView->size().width())
    {
        int size = ui->graphicsView->size().width() - (ui->graphicsView->size().width() % m_squareSize);
        m_gameTable->setSceneRect(0,0,size,size);
    }
    else
    {
        int size = ui->graphicsView->size().height() - (ui->graphicsView->size().height() % m_squareSize);
        m_gameTable->setSceneRect(0,0,size,size);
    }
    Q_UNUSED(event);
}

