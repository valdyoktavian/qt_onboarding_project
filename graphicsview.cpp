#include "graphicsview.h"
#include <QPainterPath>
#include <QGraphicsRectItem>
GraphicsView::GraphicsView(QWidget *parent, QGraphicsScene *scene)
    :scene(scene), type(-1)
{
    setMouseTracking(true);
}
GraphicsView::~GraphicsView() {}

void GraphicsView::mousePressEvent(QMouseEvent *event)
{

    if (event->button() == Qt::LeftButton) {
        QPointF scenePos = mapToScene(event->pos());
        this->spline.addPoint(scenePos);
        isDrawing = true;

    }

    QPointF scenePos = mapToScene(event->pos());
    this->spline.addPoint(scenePos);
    isDrawing = true;
    qInfo() << "test 234239" << this->spline.points_list.size();
    QGraphicsView::mousePressEvent(event);
}


void GraphicsView::mouseMoveEvent(QMouseEvent *event)
{
    if (type == 0){

    if (isDrawing){
    QPointF scenePos = mapToScene(event->pos());
        this->spline.addPoint(scenePos);}

    if (spline.points_list.size() < 2){
        return;
    }
    if (isDrawing && (event->buttons() & Qt::LeftButton)) {
        QPainterPath path;
        path.moveTo(this->spline.points_list[0]);  // start path at first point

        for (int i = 1; i < this->spline.points_list.size() - 1; ++i) {
            QPointF mid = (this->spline.points_list[i] + this->spline.points_list[i+1]) / 2;
            path.quadTo(this->spline.points_list[i], mid);  // quadratic Bézier between points
        }

        path.lineTo(this->spline.points_list.last());

        this->scene->addPath(path, QPen(Qt::white));
    }
    QGraphicsView::mouseMoveEvent(event);
    }
    if (type == 1 && isDrawing)
    {
        QPointF end = mapToScene(event->pos());
        if (this->spline.points_list.size() < 2){
            this->spline.addPoint(end);
            return;
        }
        this->scene->removeItem(this->rectangle);
        this->spline.points_list.pop_back();

        qInfo() << "test 1";
        int x_old = this->spline.points_list[0].x();
        int y_old = this->spline.points_list[0].y();
        int x_new = this->spline.points_list[1].x();
        int y_new = this->spline.points_list[1].y();

        int x_left_corner = std::min(x_old, x_new);
        int y_left_corner = std::min(y_old, y_new);
        int x_right_corner = std::max(x_old, x_new);
        int y_right_corner = std::max(y_old, y_new);
        qInfo() << "test 2";
        QGraphicsRectItem *rect = this->scene->addRect(x_left_corner, y_left_corner, x_right_corner-x_left_corner, y_right_corner - y_left_corner, QPen(Qt::white));
        this->rectangle = rect;
        splineDrawing s;
        this->spline = s;
        qInfo() << "test 3";
    }
}

void GraphicsView::mouseReleaseEvent(QMouseEvent *event)
{
    qInfo() << type;
    if (type == 0){

    if (event->button() == Qt::LeftButton) {
        isDrawing = false;
        splineDrawing s;
        this->spline = s;
    }

    }
    else if (type == 1)
    {
        isDrawing = false;

    }
     QGraphicsView::mouseReleaseEvent(event);
}

