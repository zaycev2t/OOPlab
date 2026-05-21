#include "mytextbrowser.h"
#include <QString>

MyTextBrowser::MyTextBrowser(QWidget *parent)
    : QTextBrowser(parent)
{
}

void MyTextBrowser::appendHuman(const Human& human)
{
    QString line = QString("имя: %1, рост: %2, вес: %3")
                       .arg(QString::fromStdString(human.getName()))
                       .arg(human.getHeight())
                       .arg(human.getWeight());
    append(line);
}

void MyTextBrowser::appendStudent(const Student& student)
{
    QString line = QString("имя: %1, рост: %2, вес: %3, средний балл: %4")
                       .arg(QString::fromStdString(student.getName()))
                       .arg(student.getHeight())
                       .arg(student.getWeight())
                       .arg(student.getAvgSc());
    append(line);
}
