#ifndef CYLINDER_H
#define CYLINDER_H

#include <QString>
class Cylinder
{
public:
    Cylinder(float radius, float width, int type);
    ~Cylinder();

    // fields
    float radius;
    float width;
    int type; // 0 for U, 1 for B, 2 for T

    // setters and getters
    float get_radius();
    float get_width();
    int get_type();
    void set_radius(float radius);
    void set_width(float width);
    void set_type(QString space, QString model);
};

#endif // CYLINDER_H
