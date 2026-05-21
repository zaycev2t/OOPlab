#ifndef MYTEXTBROWSER_H
#define MYTEXTBROWSER_H

#include <QTextBrowser>
#include "human.h"
#include "student.h"

class MyTextBrowser : public QTextBrowser
{
    Q_OBJECT

public:
    explicit MyTextBrowser(QWidget *parent = nullptr);

    void appendHuman(const Human& human);
    void appendStudent(const Student& student);

};

#endif
