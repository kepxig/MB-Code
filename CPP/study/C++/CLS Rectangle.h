#ifndef _RECTANGLE_H
#define _RECTANGLE_H
#include "CLS Point.h"
//派生类定义
class Rectangle : public Point
{
public:
    void initRectangle(float x, float y, float w, float h)
    {
        initPoint(x, y);
        this->W = w;
        this->H = h;
    }
    float getH() const { return H; }
    float getW() const { return W; }

private:
    float W, H;
};
#endif