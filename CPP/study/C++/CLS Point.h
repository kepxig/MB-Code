#ifndef _POINT_H
#define _POINT_H
#include <iostream>
#include <math.h>
class Point
{
private:
    float X, Y;

public:
    float distance() const;
    void initPoint(float, float);
    void move(float, float);
    float getX() const;
    float getY() const;
};
inline float Point::distance() const
{
    return sqrt((int)X ^ (int)X + (int)Y ^ (int)Y);
}
inline void Point::initPoint(float x, float y)
{
    X = x;
    Y = y;
}
inline void Point::move(float x, float y)
{
    X += x;
    Y += y;
}
inline float Point::getX() const { return X; }
inline float Point::getY() const { return Y; }
#endif
/*
1、成员函数需要把实现放在头文件中才会是默认内联函数，如果没有放在头文件中则不会默认是内联；

2、内联与否，只是你的建议，是否真正内联，得看编译器的意思，写了inline，或者你把类方法实现写在头文件，意味着你希望编译器帮你内联，但是是否真正内联，要看编译器，如果你的内联函数写得很复杂，编译器不一定会帮你内联；

3、 一般需要重复使用的短小函数用内联。
*/