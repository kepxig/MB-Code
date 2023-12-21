#include "graphics.h"
void CircleFill4(int xc, int yc, int r, int seedx, int seedy, int color)
{
   int fill = getpixel(seedx, seedy);
   if (((seedx - xc) * (seedx - xc) + (seedy - yc) * (seedy - yc) <= r * r) && (fill != color))
   {
      putpixel(seedx, seedy, color);
      CircleFill4(xc, yc, r, seedx + 1, seedy, color);
      CircleFill4(xc, yc, r, seedx - 1, seedy, color);
      CircleFill4(xc, yc, r, seedx, seedy + 1, color);
      CircleFill4(xc, yc, r, seedx, seedy - 1, color);
   }
}
int main()
{
   int gdriver = DETECT, gmode;
   initgraph(&gdriver, &gmode, "");
   CircleFill4(100, 100, 30, 110, 90, 2);
   getch();
}