#include "drawingwidget.h"
#include "jsonfigurereader.h"
#include <QPainter>
#include <QDebug>

DrawingWidget::DrawingWidget(QWidget *parent)
    : QWidget(parent)
{
    JsonFigureReader reader;
    if (reader.open("figures.json")) {
        try {
            m_figures = reader.readAll();
        } catch (const std::exception& e) {
            qDebug() << "Ошибка чтения фигур:" << e.what();
        }
    } else {
        qDebug() << "Не удалось открыть файл";
    }
}

void DrawingWidget::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    QPen pen(Qt::red, 3);
    painter.setPen(pen);
    painter.setBrush(QBrush(Qt::green));

    for (const auto& figure : m_figures) {
        figure->paint(painter);
    }
}
