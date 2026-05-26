// #include "mainwindow.h"
// #include "./ui_mainwindow.h"
// #include "csvwriter.h"
// #include "human.h"
// #include "student.h"
// #include "csvreader.h"
// #include "mytextbrowser.h"
// #include <QFileDialog>
// #include <memory>
// #include "AbstractReader.h"
// #include "JsonReader.h"
// #include "CsvParseException.h"


// void MainWindow::on_radioButton_student_toggled(bool checked)
// {
//     ui->doubleSpinBox->setVisible(checked);
//     ui->plainTextEdit_6->setVisible(checked);
// }

// void MainWindow::refresh()
// {
//     ui->textBrowser->clear();
//     ui->textBrowser->append("Текущий файл: " + QString::fromStdString(m_currentFileName));

//     std::unique_ptr<AbstractReader> reader;
//     std::string ext = m_currentFileName.substr(m_currentFileName.find_last_of('.') + 1);
//     if (ext == "csv") {
//         reader = std::make_unique<CsvReader>();
//     } else if (ext == "json") {
//         reader = std::make_unique<JsonReader>();
//     } else {
//         ui->textBrowser->append("Неподдерживаемый формат файла: " + QString::fromStdString(ext));
//         return;
//     }

//     reader->open(m_currentFileName);
//     if (!reader->is_open()) {
//         ui->textBrowser->append("Ошибка открытия файла: " + QString::fromStdString(m_currentFileName));
//         return;
//     }

//     try {
//         auto result = reader->readAll();
//         m_humans = result.first;
//         m_students = result.second;
//     } catch (const CsvParseException& e) {
//         ui->textBrowser->append(QString("<font color='red'>Ошибка в CSV файле (строка %1): %2</font>")
//                                     .arg(e.lineNumber())
//                                     .arg(e.what()));
//         return;
//     }

//     std::sort(m_humans.begin(), m_humans.end(),
//               [](Human a, Human b){ return a.getHeight() < b.getHeight();});
//     for (auto h : m_humans) {
//         ui->textBrowser->appendHuman(h);
//     }
//     std::sort(m_students.begin(), m_students.end(),
//               [](Student a, Student b){ return a.getHeight() < b.getHeight();});
//     for (auto s : m_students) {
//         ui->textBrowser->appendStudent(s);
//     }
// }

// MainWindow::MainWindow(QWidget *parent)
//     : QMainWindow(parent)
//     , ui(new Ui::MainWindow)
//     , m_currentFileName("humans.csv")
// {
//     ui->setupUi(this);
//     ui->doubleSpinBox->setVisible(0);
//     ui->plainTextEdit_6->setVisible(0);

//     refresh();
// }

// MainWindow::~MainWindow()
// {
//     delete ui;
// }


// void MainWindow::on_pushButton_search_clicked()
// {
//     QString searchName = ui->lineEdit_search->text().trimmed();
//     if (searchName.isEmpty()) {
//         ui->textBrowser->append("Введите имя для поиска.");
//         return;
//     }
//     std::string target = searchName.toStdString();
//     bool found = false;

//     for (const Human& h : m_humans) {
//         if (h.getName() == target) {
//             ui->textBrowser->append("Найден");
//             ui->textBrowser->appendHuman(h);
//             found = true;
//         }
//     }
//     if (!found){
//         for (const Student& s : m_students) {
//             if (s.getName() == target) {
//                 ui->textBrowser->append("Найден");
//                 ui->textBrowser->appendStudent(s);
//                 found = true;
//             }
//         }
//     }
//     if (!found) {
//         ui->textBrowser->append("Человек с таким именем не найден.");
//     }
// }

// void MainWindow::on_pushButton_write_clicked()
// {
//     if (ui->radioButton_student->isChecked()) {
//         QString writeName = ui->lineEdit_name->text().trimmed();
//         QString writeWeight = ui->lineEdit_weight->text().trimmed();
//         QString writeHeight = ui->lineEdit_height->text().trimmed();
//         double avg = ui->doubleSpinBox->value();
//         if (writeName.isEmpty()) {
//             ui->textBrowser->append("ERROR Введите имя");
//         }
//         if (writeHeight.isEmpty()) {
//             ui->textBrowser->append("ERROR Введите рост");
//         }
//         if (writeWeight.isEmpty()) {
//             ui->textBrowser->append("ERROR Введите вес");
//         }
//         int Weight0 = writeWeight.toInt();
//         int Height0 = writeHeight.toInt();
//         std::string Name0 = writeName.toStdString();
//         Student newstudent;
//         newstudent.setHeight(Height0);
//         newstudent.setWeight(Weight0);
//         newstudent.setName(Name0);
//         newstudent.setAvgSc(avg);
//         CsvWriter ofcsv;
//         ofcsv.open("humans.csv", std::ios::app);
//         if (ofcsv.is_open()){
//             ofcsv.write(newstudent);
//         }
//         else {
//             ui->textBrowser->append("ERROR ошибка в записи файла");
//         }
//         ofcsv.close();
//     }
//     else{
//         QString writeName = ui->lineEdit_name->text().trimmed();
//         QString writeWeight = ui->lineEdit_weight->text().trimmed();
//         QString writeHeight = ui->lineEdit_height->text().trimmed();
//         if (writeName.isEmpty()) {
//             ui->textBrowser->append("ERROR Введите имя");
//         }
//         if (writeHeight.isEmpty()) {
//             ui->textBrowser->append("ERROR Введите рост");
//         }
//         if (writeWeight.isEmpty()) {
//             ui->textBrowser->append("ERROR Введите вес");
//         }
//         int Weight0 = writeWeight.toInt();
//         int Height0 = writeHeight.toInt();
//         std::string Name0 = writeName.toStdString();

//         Human newhuman;
//         newhuman.setHeight(Height0);
//         newhuman.setWeight(Weight0);
//         newhuman.setName(Name0);

//         CsvWriter ofcsv;
//         ofcsv.open("humans.csv", std::ios::app);
//         if (ofcsv.is_open()){
//             ofcsv.write(newhuman);
//         }
//         else {
//             ui->textBrowser->append("ERROR ошибка в записи файла");
//         }
//         ofcsv.close();
//     }
//     refresh();
// }

// void MainWindow::on_pushButton_browse_clicked()
// {
//     QString fileName = QFileDialog::getOpenFileName(
//         this,
//         tr("Выберите файл с данными"),
//         QString(),
//         tr("CSV files (*.csv);;JSON files (*.json);;All files (*.*)")
//         );
//     if (fileName.isEmpty())
//         return;

//     m_currentFileName = fileName.toStdString();
//     refresh();
// }
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_drawingWidget = new DrawingWidget(this);
    setCentralWidget(m_drawingWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}
