#include"graphics.h"
typedef struct point{  int x,y;}POINT;
void EdgeMark(int x1,int y1,int x2,int y2,int color)/*DDALine_all*/
{
    int i,length;
    float dx,dy,x=x1,y=y1;
    if (abs(x2-x1)>=abs (y2-y1))
       length=abs(x2-x1);
    else
       length=abs(y2-y1);
    dx=(float)(x2-x1)/length;
    dy=(float)(y2-y1)/length;

    putpixel((int)(x+0.5),(int)(y+0.5),color);
    for(i=1;i<=length;i++)
    {
        x=x+dx;
        y=y+dy;
	putpixel((int)(x+0.5),(int)(y+0.5),color);
    }
}
void boundaryfill4(int seedx,int seedy,int fcolor,int bcolor)
{
   int current=getpixel(seedx,seedy);
   if((current!=bcolor)&&(current!=fcolor))
   {
       putpixel(seedx,seedy,fcolor);
       boundaryfill4(seedx+1,seedy,fcolor,bcolor);
       boundaryfill4(seedx-1,seedy,fcolor,bcolor);
       boundaryfill4(seedx,seedy+1,fcolor,bcolor);
       boundaryfill4(seedx,seedy-1,fcolor,bcolor);
   }
}
void SeedFill(int cnt,POINT *pts,int seedx,int seedy,int fcolor,int bcolor)
{
   POINT v1,v2;
   int i;
   for(i=0;i<cnt-1;i++)
   {
       v1=pts[i]; v2=pts[i+1];
       EdgeMark(v1.x,v1.y,v2.x,v2.y,bcolor);
   }
   boundaryfill4(seedx,seedy,fcolor,bcolor);
}
void main()
{
   POINT pts[7];
   int gdriver=DETECT,gmode;
/*
   pts[0].x=40;pts[0].y=10;
   pts[1].x=80;pts[1].y=40;
   pts[2].x=120;pts[2].y=20;
   pts[3].x=140;pts[3].y=70;
   pts[4].x=70;pts[4].y=100;
   pts[5].x=20;pts[5].y=60;
   pts[6].x=40;pts[6].y=10;
*/
   pts[0].x=10;pts[0].y=10;
   pts[1].x=80;pts[1].y=10;
   pts[2].x=80;pts[2].y=80;
   pts[3].x=10;pts[3].y=80;
   pts[4].x=10;pts[4].y=10;

   initgraph(&gdriver,&gmode,"");
   /*SeedFill(7,pts,75,80,2,3);*/
   SeedFill(5,pts,45,40,2,3);
   getch();
}