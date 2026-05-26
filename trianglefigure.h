#ifndef TRIANGLEFIGURE_H
#define TRIANGLEFIGURE_H

#include "Figure.h"
#include <QPolygon>

class TriangleFigure : public Figure {
public:
    TriangleFigure() = default;

    void setPolygon(const QPolygon& polygon) { m_polygon = polygon; }
    QPolygon polygon() const { return m_polygon; }

    void paint(QPainter& painter) const override {
        painter.drawPolygon(m_polygon);
    }

private:
    QPolygon m_polygon;
};

#endif // TRIANGLEFIGURE_H
