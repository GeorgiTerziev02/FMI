#pragma once
#include "Shape.h"
class Rhombus :
    public Shape
{
    double aLength;
    float angle;
public:
    Rhombus(int, int, const String&, double, float);
    double getArea() const override;
    void getInfo() const override;
};

