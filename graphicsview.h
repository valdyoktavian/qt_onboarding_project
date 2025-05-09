#ifndef GRAPHICSVIEW_H
#define GRAPHICSVIEW_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMouseEvent>
#include "splinedrawing.h"
#include <QGraphicsRectItem>
#include "drawable.h"
#include "freedraw.h"
#include "square.h"
#include <QDialog>
#include <ui_dialog.h>
#include "cylinder.h"
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

    QList<drawable*> list;
    void draw_screen();
    void add_item(drawable *item);
    void change_current_item(drawable *item);
    // bool first_iteration;
    QPointF initial_point;
    int index;

    Ui::Dialog *ui;
    Cylinder *cylinder;
};

#endif // GRAPHICSVIEW_H
