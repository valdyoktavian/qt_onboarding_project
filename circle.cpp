#include "circle.h"

circle::circle(int x1, int y1, int x2, int y2) {
    QPointF c(x1, y1);
    int dx = x1 - x2;
    int dy = y1 - y2;
    int radius = std::sqrt((dx * dx) + (dy * dy));
    this->center = c;
    this->radius = radius;
}

void circle::draw_object(QGraphicsScene *scene){
    int diameter = 2*this->radius;
    QRectF rect(center.x()-this->radius, center.y()-this->radius, diameter, diameter);
    scene->addRect(rect, QPen(Qt::white));
}

