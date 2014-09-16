#include "project.h"

#include <QMessageBox>

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

    QString path = files.at(0);
    if (path != NULL)
    {
        QDir().mkdir(path);
        QDir().mkdir(path + "/Assets");
        QDir().mkdir(path + "/Scripts");
        this->path = path;
        QFileInfo qfi = QFileInfo(path);
        this->name = qfi.fileName();
        QFile file = QFile(this->path + "/" + this->name + ".agp");
        file.open(QIODevice::WriteOnly | QIODevice::Text);
        QTextStream out(&file);
        out << "<project name = " + this->name +
               " path = " + this->path + "></project>";
        file.close();
    }
}

void Project::Open(QFileDialog *qFileDialog)
{

}
