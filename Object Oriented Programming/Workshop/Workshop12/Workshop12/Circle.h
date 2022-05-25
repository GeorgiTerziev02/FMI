#pragma once
#include "Shape.h"
class Circle :
    public Shape
{
    double diameter;
public:
    Circle(int, int, const String&, double);
    double getArea() const override;
    void getInfo() const override;
};

