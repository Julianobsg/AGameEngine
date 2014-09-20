#include "project.h"

#include <QMessageBox>
#include <QTextStream>

Project::Project()
{
}

void Project::New(QFileDialog *qFileDialog)
{
    qFileDialog->setWindowModality(Qt::WindowModal);
    qFileDialog->setAcceptMode(QFileDialog::AcceptSave);
    qFileDialog->setFileMode(QFileDialog::Directory);
    qFileDialog->exec();
    QStringList files = qFileDialog->selectedFiles();
    if (!files.empty())
    {
        QString path = files.at(0);
        if (path != NULL)
        {
            QDir().mkdir(path);
            QDir().mkdir(path + "/Assets");
            QDir().mkdir(path + "/Scripts");
            QDir().mkdir(path + "/Projects");
            this->path = path;
            QFileInfo qfi = QFileInfo(path);
            this->name = qfi.fileName();
            QFile* file = new QFile(this->path + "/" + this->name + ".agp");
            file->open(QIODevice::WriteOnly | QIODevice::Text);
            QTextStream out(file);
            out << "<project name = " + this->name +
                   " path = " + this->path + "></project>";
            file->close();
        }
    }
}

void Project::Open(QFileDialog *qFileDialog)
{

    QString fileName = qFileDialog->getOpenFileName();
    if (!fileName.isEmpty())
    {
        QFileInfo qfi = QFileInfo(path);
        this->name = qfi.fileName();
        name = fileName;
    }
}
