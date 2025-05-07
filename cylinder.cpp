#include "cylinder.h"

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

