#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "project.h"

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionNew_Project_triggered(bool checked);

private:
    Ui::MainWindow *ui;
    Project* project;
    void SetTitle(QString title);
};

#endif // MAINWINDOW_H
