#include "splinedrawing.h"

splineDrawing::splineDrawing() {}

void splineDrawing::addPoint(QPointF p)
{
    this->points_list.push_back(p);
}
