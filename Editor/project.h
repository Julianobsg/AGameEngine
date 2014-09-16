#ifndef PROJECT_H
#define PROJECT_H
#include <QFileDialog>

class Project
{
public:
    QString name;
    QString path;

    Project();
    void New(QFileDialog* qFileDialog);

    void Open(QFileDialog* qFileDialog);
};

#endif // PROJECT_H
