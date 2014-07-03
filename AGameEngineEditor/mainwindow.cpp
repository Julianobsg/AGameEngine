#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    project = new Project;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNew_Project_triggered(bool checked)
{
    if (!checked) {
        QFileDialog qfile(this);
        project->New(&qfile);
        SetTitle(project->path);
    }
}

void MainWindow::SetTitle(QString title)
{
    if (title.isEmpty())
        title = "Still no project";
    setWindowTitle(title);
}
