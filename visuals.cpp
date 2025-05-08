#include "visuals.h"
#include "cylinder.h"
#include "dialog.h"
#include "ui_dialog.h"

Visuals::Visuals() {}

Visuals::~Visuals(){}

void Visuals::create_visuals(Cylinder *cylinder, Ui::Dialog *ui, QGraphicsScene *scene)
{

    float radius = cylinder->get_radius();
    float width = cylinder->get_width();
    // qInfo() << "test, radius and width are: " << radius << width;
    if (cylinder->get_radius() == 0 || cylinder->get_width() == 0)
    {
        // qInfo() << "radius or width is 0";
        return;
    }

    if (cylinder->get_type() == 0)
    {
        // make the default cylinder
        // qInfo() << "test, radius and width are: " << radius << width;
        int y = radius + width;
        // Bottom ellipse (cylinder bottom)
        scene->addEllipse(50, y, radius*2, radius/2, QPen(Qt::lightGray), QBrush(Qt::lightGray));

        // Body (cylinder body)
        scene->addRect(50, y - width + radius/4, radius*2, width, QPen(Qt::lightGray), QBrush(Qt::lightGray));

        // Top ellipse (cylinder top)
        scene->addEllipse(50, y - width, radius*2,  radius/2, QPen(Qt::black), QBrush(Qt::gray));
    }
    else if(cylinder->type == 1)
    {
        // make the long cylinder

        int x = radius + width;
        // Bottom ellipse (cylinder bottom)
        scene->addEllipse(x, 100, radius/2, radius*2, QPen(Qt::lightGray), QBrush(Qt::lightGray));

        // Body (cylinder body)
        scene->addRect(x-width + radius/4, 100, width, radius*2, QPen(Qt::lightGray), QBrush(Qt::lightGray));

        // Top ellipse (cylinder top)
        scene->addEllipse(x - width, 100, radius/2, radius*2, QPen(Qt::black), QBrush(Qt::gray));
    }
    else if (cylinder->type == 2)
    {
        // circle
        if (radius > 192/2) {
            radius = 191;
        }
        scene->addRect(0, 0, 484, 192, Qt::NoPen, QBrush(Qt:: lightGray));
        scene->addEllipse(484/2-radius/2, 192/2-radius/2, radius, radius, QPen(Qt::black), QBrush(Qt::gray));
    }
    else
    {
        delete(scene);
        return;
    }
    ui->graphicsView->setScene(scene);
    scene->setSceneRect(scene->itemsBoundingRect());
    ui->graphicsView->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);
}

void Visuals::change_visuals(Cylinder *cylinder, Ui::Dialog *ui, QGraphicsScene *scene)
{
    scene->clear();
    ui->graphicsView->setScene(scene);

    create_visuals(cylinder, ui, scene);
}
