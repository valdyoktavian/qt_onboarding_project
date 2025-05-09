#include "freedraw.h"
#include <QPainterPath>

freedraw::freedraw(int x1, int y1) {
    QPointF p(x1, y1);
    QList<QPointF> new_list;
    this->points_list = new_list;
    this->points_list.push_back(p);
}

void freedraw::addPoint(QPointF p){
    this->points_list.push_back(p);
}

void freedraw::draw_object(QGraphicsScene *scene){
    QPainterPath path;
    path.moveTo(this->points_list[0]);  // start path at first point

    for (int i = 1; i < this->points_list.size() - 1; ++i) {
        QPointF mid = (this->points_list[i] + this->points_list[i+1]) / 2;
        path.quadTo(this->points_list[i], mid);  // quadratic Bézier between points
    }

    path.lineTo(this->points_list.last());

    scene->addPath(path, QPen(Qt::white));
}
