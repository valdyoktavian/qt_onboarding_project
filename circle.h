#ifndef CIRCLE_H
#define CIRCLE_H
#include "drawable.h"

class circle : public drawable
{
public:
    circle(int x1, int y1, int x2, int y2);
    int radius;
    QPointF center;

    void draw_object(QGraphicsScene *scene) override;
};

#endif // CIRCLE_H
