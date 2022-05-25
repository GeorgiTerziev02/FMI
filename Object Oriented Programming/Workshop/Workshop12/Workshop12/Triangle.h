#pragma once
#include "Shape.h"
#include "String.h"
class Triangle :
    public Shape
{
    double aLength, bLength;
    float aAngle;
public:
    Triangle(int, int, const String&, double, double, float);
    double getArea() const override;
    void getInfo() const override;
};

