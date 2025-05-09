#include "graphicsview.h"
#include <QPainterPath>
#include <QGraphicsRectItem>
GraphicsView::GraphicsView(QWidget *parent, QGraphicsScene *scene)
    :scene(scene), type(5), index(0), isDrawing(false)
{
    setMouseTracking(true);
}
GraphicsView::~GraphicsView() {}

void GraphicsView::mousePressEvent(QMouseEvent *event)
{

    if (type == 5)
        return;

    if (event->button() == Qt::LeftButton) {
        QPointF scenePos = mapToScene(event->pos());
        this->initial_point = scenePos;
        this->isDrawing = true;

        if (type == 0){
            freedraw* item = new freedraw(scenePos.x(), scenePos.y());
            this->add_item(item);
        }
        if (type == 1){
            this->initial_point = scenePos;
            this->add_item(new square(0,0,0,0));
        }
    }
    QGraphicsView::mousePressEvent(event);
}


void GraphicsView::mouseMoveEvent(QMouseEvent *event)
{
    if (type == 5)
        return;

    QPointF scenePos = mapToScene(event->pos());
    if (!this->isDrawing)
        return;

    if (type == 0){
        freedraw* s = dynamic_cast<freedraw*>(this->list.last());
        s->addPoint(scenePos);
    }
    if (type == 1){
        square *s = new square(this->initial_point.x(), this->initial_point.y(), scenePos.x(), scenePos.y());
        this->change_current_item(s);
    }
    this->scene->clear();
    this->draw_screen();
    this->cylinder->draw_object(this->scene);
}

void GraphicsView::mouseReleaseEvent(QMouseEvent *event)
{
    qInfo() << type;
    if (event->button() == Qt::LeftButton) {
        isDrawing = false;
        this->index = this->index + 1;
        return;
    }

    else if (type == 1)
    {
        isDrawing = false;

    }
     QGraphicsView::mouseReleaseEvent(event);
}

void GraphicsView::draw_screen(){
    qInfo() << this->list.size();
    for (int i = 0; i < this->list.size(); i++){
        list[i]->draw_object(this->scene);
        qInfo() << "teettt" << i;
    }
}

void GraphicsView::add_item(drawable *item){
        this->list.push_back(item);
}

void GraphicsView::change_current_item(drawable *item){
    this->list.pop_back();
    this->list.push_back(item);
}



