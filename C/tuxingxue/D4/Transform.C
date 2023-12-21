
#include "graphics.h"
#include "math.h"
typedef struct point{ int x,y;}POINT;

void ScaleTransform(POINT p[20],int m,float ScaleX,float ScaleY)
{
    int i;
    for(i=0;i<m;i++)
    {
	p[i].x=p[i].x*ScaleX;
	p[i].y=p[i].y*ScaleY;
    }
}

void MirrorTransform(POINT p[20],int m,POINT ps,POINT pe)
{
    int i;POINT p1[20];double A,B,C;
    A=pe.y-ps.y;B=ps.x-pe.x;
    C=-A*ps.x-B*ps.y;
    for(i=0;i<m;i++)
    {
	p1[i].x=((B*B-A*A)*p[i].x-2*A*B*p[i].y-2*A*C)/(A*A+B*B);
	p1[i].y=((A*A-B*B)*p[i].y-2*A*B*p[i].x-2*B*C)/(A*A+B*B);
    }
    for(i=0;i<m;i++)
    {
	p[i].x=p1[i].x;  p[i].y=p1[i].y;
    }
}

void SkewTransform(POINT p[20],int m,float SkewX,float SkewY)
{
    int i;
    for(i=0;i<m;i++)
    {
	p[i].x=p[i].x+p[i].y*SkewX;
	p[i].y=p[i].x*SkewY+p[i].y;
    }
}
void RotateTransform(POINT p[20],int m,POINT Cen,float theta)
{
    int i;double a,b,c,d;
    POINT p1[20];
    double alfa=theta*3.1415926/180;
    a=cos(alfa);b=sin(alfa);
    for(i=0;i<m;i++)
    {
	p1[i].x=p[i].x*a-p[i].y*b+Cen.x*(1-a)+Cen.y*b;
	p1[i].y=p[i].x*b+p[i].y*a-Cen.x*b+Cen.y*(1-a);
    }
    for(i=0;i<m;i++)
    {   p[i].x=p1[i].x;p[i].y=p1[i].y;}
}
void MoveTransform(POINT p[20],int m,float MoveX,float MoveY)
{
    int i;
    for(i=0;i<m;i++)
    {	p[i].x=p[i].x+MoveX;p[i].y=p[i].y+MoveY;}
}

void main()
{
    int i,n=5;
    int GraphDriver=0,GraphMode;
    POINT p[20],p1,p2;
    p[0].x=150;p[0].y=220;
    p[1].x=120;p[1].y=120;
    p[2].x=270;p[2].y=100;
    p[3].x=230;p[3].y=180;
    p[4].x=150;p[4].y=220;
    p1.x=80;p1.y=350;p2.x=350;p2.y=80;
    initgraph(&GraphDriver,&GraphMode,"");
    setcolor(2);
    moveto(p[0].x,p[0].y);
    for(i=1;i<n;i++)
       lineto(p[i].x,p[i].y);
/*    ScaleTransform(p,n,2,2);*/
    MirrorTransform(p,n,p1,p2);
    setcolor(3);
    moveto(p1.x,p1.y);lineto(p2.x,p2.y);
/*  SkewTransform(p,n,1,0.5);*/
/*    RotateTransform(p,n,p1,40);*/
/*  MoveTransform(p,n,40,30);*/
    setcolor(4);
    moveto(p[0].x,p[0].y);
    for(i=1;i<n;i++)
	lineto(p[i].x,p[i].y);
    getch();
    closegraph();
/*    for(i=0;i<n;i++)
       printf("%d=%d,%d\n",i,p[i].x,p[i].y);*/
}