#ifndef SQUARE_H
#define SQUARE_H

#include "drawable.h"

class square : public drawable
{
public:
    square(int x1, int y1, int x2, int y2);
    QPointF top_left;
    QPointF bottom_right;

    void draw_object(QGraphicsScene *scene) override;
};

#endif // SQUARE_H
