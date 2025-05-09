#ifndef FREEDRAW_H
#define FREEDRAW_H
#include "drawable.h"

class freedraw : public drawable
{
public:
    freedraw(int x1, int y1);
    QList<QPointF> points_list;
    void addPoint(QPointF p);

    void draw_object(QGraphicsScene *scene) override;
};

#endif // FREEDRAW_H
