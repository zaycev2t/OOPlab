#ifndef RECTANGLEFIGURE_H
#define RECTANGLEFIGURE_H

#include "Figure.h"

class RectangleFigure : public Figure {
public:
    RectangleFigure() = default;

    void setSize(int width, int height) {
        m_width = width;
        m_height = height;
    }

    void paint(QPainter& painter) const override {
        painter.drawRect(pos().x(), pos().y(), m_width, m_height);
    }

private:
    int m_width = 50;
    int m_height = 30;
};

#endif // RECTANGLEFIGURE_H
