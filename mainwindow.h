#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include "human.h"
#include "student.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_search_clicked();
    void on_pushButton_write_clicked();
    void on_radioButton_student_toggled(bool checked);
    void on_pushButton_browse_clicked();


private:
    Ui::MainWindow *ui;
    std::vector<Human> m_humans;
    std::vector<Student> m_students;
    void refresh();
    std::string m_currentFileName;
};
#endif // MAINWINDOW_H
