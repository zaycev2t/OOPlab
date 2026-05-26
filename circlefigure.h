#ifndef CIRCLEFIGURE_H
#define CIRCLEFIGURE_H

#include "Figure.h"

class CircleFigure : public Figure {
public:
    CircleFigure() = default;

    void setRadius(int radius) { m_radius = radius; }

    void paint(QPainter& painter) const override {
        // Рисуем круг, вписанный в квадрат со стороной 2*radius
        painter.drawEllipse(pos().x() - m_radius, pos().y() - m_radius,
                            2 * m_radius, 2 * m_radius);
    }

private:
    int m_radius = 30;
};

#endif // CIRCLEFIGURE_H
