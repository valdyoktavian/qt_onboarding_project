#ifndef VISUALS_H
#define VISUALS_H

#include <QString>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsEllipseItem>
#include <QGraphicsRectItem>
#include "cylinder.h"
#include "dialog.h"

class Visuals
{
public:
    Visuals();
    ~Visuals();
    static void change_visuals(Cylinder *cylinder, Ui::Dialog *ui, QGraphicsScene *scene);
    static void create_visuals(Cylinder *cylinder, Ui::Dialog *ui, QGraphicsScene *scene);
};


#endif // VISUALS_H
