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
1����Ա������Ҫ��ʵ�ַ���ͷ�ļ��вŻ���Ĭ���������������û�з���ͷ�ļ����򲻻�Ĭ����������

2���������ֻ����Ľ��飬�Ƿ������������ÿ�����������˼��д��inline����������෽��ʵ��д��ͷ�ļ�����ζ����ϣ�����������������������Ƿ�����������Ҫ������������������������д�úܸ��ӣ���������һ�������������

3�� һ����Ҫ�ظ�ʹ�õĶ�С������������
*/