#ifndef FIGURE_H
#define FIGURE_H

#include <QPainter>
#include <QPoint>

class Figure {
public:
    Figure() = default;
    virtual ~Figure() = default;

    virtual void paint(QPainter& painter) const = 0;

    void setPos(const QPoint& pos) { m_pos = pos; }
    QPoint pos() const { return m_pos; }

private:
    QPoint m_pos{0, 0};
};

#endif // FIGURE_H
