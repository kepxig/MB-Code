#include "graphics.h"
void DDALine(int x1,int y1,int x2,int y2,int color)
{
    int x;
    float k,y=y1;
    k=1.0*(y2-y1)/(x2-x1);
    for(x=x1;x<=x2;x++)
    {
        putpixel(x,(int)(y+0.5),color);
        y=y+k;
    }
}
void DDALine_all(int x1,int y1,int x2,int y2,int color)
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
int Sign(int x)
{
    if(x<0) return -1;
    else if(x==0) return 0;
    else return 1;
}
void MPLine(int x1,int y1,int x2,int y2,int color)
{
    int x,y,a,b,d,d1,d2;
    a=y1-y2; b=x2-x1;
    y=y1;
    d=2*a+b; d1=2*a; d2=2*(a+b);
    putpixel(x,y,color);
    for(x=x1;x<=x2;x++)
    {
	if(d<0)	{ y++; d+=d2;}
        else {d+=d1;}
        putpixel(x,y,color);
    }
}
void MPLine_all(int x1,int y1,int x2,int y2,int color)
{
    int x,y,a,b,d1,d2,d,i,s1,s2,temp,swap;
    a=-abs(y2-y1); b=abs(x2-x1);
    x=x1; y=y1;
    s1=Sign(x2-x1);s2=Sign(y2-y1);
    if(-a>b) { temp=b;b=-a;a=-temp;swap=1;}
    else  swap=0;
    d=2*a+b; d1=2*a; d2=2*(a+b);
    putpixel(x,y,color);
    for(i=1;i<=b;i++)
    {
        if(swap==1)  y=y+s2;
        else  x=x+s1;
	if(d<0)
	{
	    if(swap==1)  x=x+s1;
            else  y=y+s2;
	    d+=d2;
	}
        else {d+=d1;}
        putpixel(x,y,color);
    }
}
void BHLine(int x1,int y1,int x2,int y2,int color)
{
    int x,y,dx,dy,dk;
    dx=abs(x2-x1);dy=abs(y2-y1);
    dk=2*dy-dx;y=y1;
    for(x=x1;x<=x2;x++)
    {
	putpixel(x,y,color);
        dk=dk+2*dy;
        if(dk>=0)
	{  y++; dk=dk-2*dx;}
    }
}
void BHLine_all(int x1,int y1,int x2,int y2,int color)
{
    int x,y,dx,dy,dk,i,s1,s2,temp,swap;
    dx=abs(x2-x1);dy=abs(y2-y1);
    x=x1;y=y1;
    s1=Sign(x2-x1);s2=Sign(y2-y1);
    if(dy>dx) { temp=dx;dx=dy;dy=temp;swap=1;}
    else  swap=0;
    dk=2*dy-dx;
    for(i=1;i<=dx;i++)
    {
	putpixel(x,y,color);
        if(swap==1)  y=y+s2;
        else  x=x+s1;
        dk=dk+2*dy;
        if(dk>=0)
	{
	    if(swap==1)  x=x+s1;
            else  y=y+s2;
            dk=dk-2*dx;
	}
    }
}
void main()
{
    int GraphDriver=0,GraphMode;
    initgraph(&GraphDriver,&GraphMode,"");
    DDALine(10,100,200,20,1);
    DDALine_all(10,10,200,120,1);
    DDALine_all(210,210,20,100,1);
    MPLine(40,160,200,60,2);
    MPLine_all(40,100,200,160,2);
    MPLine_all(250,120,60,160,2);
    BHLine(50,250,200,200,3);
    BHLine_all(50,250,200,200,3);
    BHLine_all(220,300,40,60,3);
    getch();
    closegraph();
}