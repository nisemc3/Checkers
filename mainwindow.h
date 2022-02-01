#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "gametable.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
        Q_OBJECT

    public:
        MainWindow(QWidget *parent = nullptr);
        ~MainWindow();


    private:
        Ui::MainWindow *ui;   
        GameTable* m_gameTable;
        quint8 m_squareSize = 9;

    protected:
        void resizeEvent(QResizeEvent *) override;

};
#endif // MAINWINDOW_H
