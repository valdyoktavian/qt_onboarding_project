#include "line.h"

line::line(int x1, int y1, int x2, int y2) {
    QPointF start(x1, y1);
    QPoint end (x2, y2);
}

void line::draw_object (QGraphicsScene *scene){
    QLineF line(this->start, this->end);
    scene->addLine(line, QPen(Qt::white));
}
