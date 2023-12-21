#include "graphics.h"
void WholeCircle(int xc, int yc, int x, int y, int color)
{
    putpixel(xc + x, yc + y, color);
    putpixel(xc - x, yc + y, color);
    putpixel(xc + x, yc - y, color);
    putpixel(xc - x, yc - y, color);
    putpixel(xc + y, yc + x, color);
    putpixel(xc - y, yc + x, color);
    putpixel(xc + y, yc - x, color);
    putpixel(xc - y, yc - x, color);
}
void MidCircle(int xc, int yc, int r, int color)
{
    int x, y, d;
    x = 0;
    y = r;
    d = 1 - r;
    WholeCircle(xc, yc, x, y, color);
    while (x <= y)
    {
        if (d < 0)
        {
            d += 2 * x + 3;
            x++;
        }
        else
        {
            d += 2 * (x - y) + 5;
            x++;
            y--;
        }
        WholeCircle(xc, yc, x, y, color);
    }
    WholeCircle(xc, yc, x, y, color);
}
void BresenhamCircle(int xc, int yc, int r, int color)
{
    int x, y, d;
    x = 0;
    y = r;
    d = 3 - 2 * r;
    while (x < y)
    {
        WholeCircle(xc, yc, x, y, color);
        if (d < 0)
            d = d + 4 * x + 6;
        else
        {
            d = d + 4 * (x - y) + 10;
            y--;
        }
        x++;
    }
    if (x == y)
        WholeCircle(xc, yc, x, y, color);
}
void WholeEllipse(int xc, int yc, int x, int y, int color)
{
    putpixel(xc + x, yc + y, color);
    putpixel(xc + x, yc - y, color);
    putpixel(xc - x, yc + y, color);
    putpixel(xc - x, yc - y, color);
}
void MidEllipse(int xc, int yc, int a, int b, int color)
{
    int aa = a * a, bb = b * b;
    int twoaa = 2 * aa, twobb = 2 * bb;
    int x = 0, y = b;
    int dx = 0, dy = twoaa * y;
    int d = (int)(bb + aa * (-b + 0.25) + 0.5);
    WholeEllipse(xc, yc, x, y, color);
    while (dx < dy)
    {
        x++;
        dx += twobb;
        if (d < 0)
            d += bb + dx;
        else
        {
            y--;
            dy -= twoaa;
            d += bb + dx - dy;
        }
        WholeEllipse(xc, yc, x, y, color);
    }
    d = (int)(bb * (x + 0.5) * (x + 0.5) + aa * (y - 1) * (y - 1) - aa * bb + 0.5);
    while (y > 0)
    {
        y--;
        dy -= twoaa;
        if (d > 0)
            d += aa - dy;
        else
        {
            x++;
            dx += twobb;
            d += aa - dy + dx;
        }
        WholeEllipse(xc, yc, x, y, color);
    }
}
void main()
{
    int GraphDriver = 0, GraphMode;
    initgraph(&GraphDriver, &GraphMode, "");

    MidCircle(100, 100, 70, 3);
    BresenhamCircle(140, 140, 70, 4);
    MidEllipse(250, 220, 100, 70, 5);

    getch();
    closegraph();
}