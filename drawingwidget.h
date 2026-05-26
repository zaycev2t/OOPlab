#ifndef DRAWINGWIDGET_H
#define DRAWINGWIDGET_H

#include <QWidget>
#include <memory>
#include <vector>
#include "figure.h"

class DrawingWidget : public QWidget {
    Q_OBJECT
public:
    explicit DrawingWidget(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    std::vector<std::unique_ptr<Figure>> m_figures;
};

#endif // DRAWINGWIDGET_H
