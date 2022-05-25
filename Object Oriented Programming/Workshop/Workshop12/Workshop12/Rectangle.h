#pragma once
#include "Shape.h"
class Rectangle :
    public Shape
{
    double aLength, bLength;
public:
    Rectangle(int, int, const String&, double, double);
    double getArea() const override;
    void getInfo() const override;
};

