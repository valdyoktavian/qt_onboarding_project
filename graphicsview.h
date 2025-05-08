#ifndef GRAPHICSVIEW_H
#define GRAPHICSVIEW_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMouseEvent>
#include "splinedrawing.h"
#include <QGraphicsRectItem>


class GraphicsView : public QGraphicsView
{
    Q_OBJECT

public:
    GraphicsView(QWidget *parent = nullptr, QGraphicsScene *scene = nullptr);
    ~GraphicsView();

    void mouseMoveEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

    QGraphicsScene *scene;
    QGraphicsRectItem *rectangle;
    splineDrawing spline;
    bool isDrawing;
    int type;
};

#endif // GRAPHICSVIEW_H
