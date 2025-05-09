#include "square.h"
#include <QDebug>

square::square(int x1, int y1, int x2, int y2) {
    int x_top_left = std::min(x1, x2);
    int y_top_left = std::min(y1,y2);
    QPointF p1(x_top_left, y_top_left);

    int x_bottom_right = std::max(x1,x2);
    int y_bottom_right = std::max(y1,y2);
    QPointF p2(x_bottom_right, y_bottom_right);

    this->top_left=p1;
    this->bottom_right=p2;
}

void square::draw_object(QGraphicsScene *scene){
    QRectF rect(this->top_left, this->bottom_right);
    qInfo() << "finished initialising the square";
    // scene->addRect(rect, QPen(Qt::NoPen), QBrush(Qt::white));
    scene->addRect(rect, QPen(Qt::white), QBrush(Qt::NoBrush));
}



