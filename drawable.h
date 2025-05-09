#ifndef DRAWABLE_H
#define DRAWABLE_H
#include <QGraphicsScene>
#include <QPointF>

class drawable
{
public:
    drawable();

    void virtual draw_object(QGraphicsScene *scene);
};

#endif // DRAWABLE_H
