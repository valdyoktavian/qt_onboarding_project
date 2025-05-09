#include "cylinder.h"
#include <QGraphicsScene>

Cylinder::Cylinder (float radius, float width, int type)
    :radius(radius), width(width), type(type)
{}

Cylinder::~Cylinder()
{}

void Cylinder::set_radius(float radius)
{
    this->radius = radius;
}

void Cylinder::set_width(float width)
{
    this->width = width;
}

void Cylinder::set_type(QString space, QString model)
{
    if (space == "2D") {
        this->type = 2;
    }
    else
    {
        if (model == "U")
        {
            this->type = 0;
        }
        else
        {
            this->type = 1;
        }
    }
}

float Cylinder::get_radius()
{
    return this->radius;
}

float Cylinder::get_width()
{
    return this->width;
}

int Cylinder::get_type()
{
    return this->type;
}

void Cylinder::draw_object(QGraphicsScene *scene)
{
    float radius = this->get_radius();
    float width = this->get_width();
    // qInfo() << "test, radius and width are: " << radius << width;
    if (this->get_radius() == 0 || this->get_width() == 0)
    {
        // qInfo() << "radius or width is 0";
        return;
    }

    if (this->get_type() == 0)
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
    else if(this->type == 1)
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
    else if (this->type == 2)
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
    this->ui->graphicsView->setScene(scene);
    scene->setSceneRect(scene->itemsBoundingRect());
    this->ui->graphicsView->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);
}

