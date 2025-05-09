#ifndef LINE_H
#define LINE_H
#include "drawable.h"

class line : public drawable
{
public:
    line(int x1, int y1, int x2, int y2);
    QPointF start;
    QPointF end;

    void draw_object(QGraphicsScene *scene) override;
};

#endif // LINE_H
