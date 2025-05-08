#ifndef SPLINEDRAWING_H
#define SPLINEDRAWING_H

#include <QGraphicsScene>
class splineDrawing
{
public:
    splineDrawing();

    QList<QPointF> points_list;
    void addPoint(QPointF p);
};

#endif // SPLINEDRAWING_H
