QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    csvparseexception.cpp \
    csvreader.cpp \
    csvwriter.cpp \
    drawingwidget.cpp \
    human.cpp \
    jsonfigurereader.cpp \
    jsonreader.cpp \
    main.cpp \
    mainwindow.cpp \
    mytextbrowser.cpp \
    student.cpp

HEADERS += \
    ../../OneDrive/Рабочий стол/json.hpp \
    ../../OneDrive/Рабочий стол/figures.json \
    AbstractReader.h \
    Figure.h \
    circlefigure.h \
    csvparseexception.h \
    csvreader.h \
    csvwriter.h \
    drawingwidget.h \
    human.h \
    json.hpp \
    jsonfigurereader.h \
    jsonreader.h \
    mainwindow.h \
    mytextbrowser.h \
    rectanglefigure.h \
    student.h \
    trianglefigure.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    ../../../OneDrive/Рабочий стол/figures.json
