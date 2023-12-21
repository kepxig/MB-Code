#include "graphics.h"
#define  LEFT 1
#define  RIGHT  2
#define  BOTTOM 4
#define  TOP 8
typedef struct point { int x,y;} POINT;
void Encode (int x,int y,int *code,int XL,int XR,int YB,int YT)
{
    int c=0;
    if(x<XL) c=c|LEFT;
    else if(x>XR) c=c|RIGHT;
    if (y<YB) c=c|BOTTOM;
    else if (y>YT) c=c|TOP;
    (*code)=c;
}
void C_S_Line(POINT p1,POINT p2,int XL,int XR,int YB,int YT)
{
    int x1,x2,y1,y2,x,y;
    int code1,code2,code;
    x1=p1.x;x2=p2.x;y1=p1.y;y2=p2.y;
    Encode(x1,y1,&code1,XL,XR,YB,YT);
    Encode(x2,y2,&code2,XL,XR,YB,YT);
    while(code1!=0 || code2!=0)
    {
	if ((code1 & code2) !=0) return;
	code=code1;
	if (code1==0) code=code2;
	if ((LEFT & code) !=0)
	{
	    x=XL;
	    y=y1+(y2-y1)*(XL-x1)/(x2-x1);
	}
	else if((RIGHT & code)!=0)
	{
	    x=XR;
	    y=y1+(y2-y1)*(XR-x1)/(x2-x1);
	}
	else if((BOTTOM & code) != 0)
	{
	    y=YB;
	    x=x1+(x2-x1)*(YB-y1)/(y2-y1);
	}
	else if((TOP & code)!=0)
	{
	    y=YT;
	    x=x1+(x2-x1)*(YT-y1)/(y2-y1);
	}
        if(code==code1)
	{
	    x1=x; y1=y;
	    Encode(x,y,&code1,XL,XR,YB,YT);
	}
    	else
	{
	    x2=x; y2=y;
	    Encode(x,y,&code2,XL,XR,YB,YT);
	}
    }
    p1.x=x1;p1.y=y1;p2.x=x2;p2.y=y2;
    moveto(p1.x,p1.y);lineto(p2.x,p2.y);
}
int IsInArea(POINT point,int XL,int XR,int YB,int YT)
{
    if(point.x>=XL && point.x<=XR && point.y>YB && point.y<YT)
	return 1;
    else
	return 0;
}
int NotIntersect(POINT begin,POINT end,int XL,int XR,int YB,int YT)
{
    int maxx,maxy,minx,miny;
    maxx=(begin.x>end.x)?begin.x:end.x;
    minx=(begin.x<end.x)?begin.x:end.x;
    maxy=(begin.y>end.y)?begin.y:end.y;
    miny=(begin.y<end.y)?begin.y:end.y;

    if(maxx<XL || minx>XR || maxy<YB || miny>YT)
	return 1;
    else
	return 0;
}
POINT ClipMid(POINT begin,POINT end,int XL,int XR,int YB,int YT)
{
    POINT mid,temp;
    if(IsInArea(begin,XL,XR,YB,YT))
        temp=begin;
    else if(NotIntersect(begin,end,XL,XR,YB,YT))
	temp=begin;
    else
    {
	mid.x=(begin.x+end.x)/2;
	mid.y=(begin.y+end.y)/2;
	if(abs(mid.x-end.x)<=1 && abs(mid.y-end.y)<=1)
	    temp=mid;
	else
	{
	    if(NotIntersect(begin,mid,XL,XR,YB,YT))
		temp=ClipMid(mid,end,XL,XR,YB,YT);
	    else
		temp=ClipMid(begin,mid,XL,XR,YB,YT);
	}
    }
    return temp;
}
void MPClip(POINT begin,POINT end,int XL,int XR,int YB,int YT)
{
    POINT p1,p2;
    p1=ClipMid(begin,end,XL,XR,YB,YT);
    p2=ClipMid(end,begin,XL,XR,YB,YT);
    moveto(p1.x,p1.y);lineto(p2.x,p2.y);
}
int clipTest(float p,float q,float *u1,float *u2)
{
    float r;
    int remainFlag=1;
    if(p<0.0)
    {
	r=q/p;
	if(r>*u2) remainFlag=0;
	else if(r>*u1) *u1=r;
    }
    else if(p>0.0)
    {
	r=q/p;
	if(r<*u1) remainFlag=0;
	else if(r<*u2) *u2=r;
    }
    else
	if(q<0.0) remainFlag=0;
    return remainFlag;
}
void ClipParameter(POINT p1,POINT p2,int XL,int XR,int YB,int YT)
{
    float u1=0.0,u2=1.0;
    float dx=p2.x-p1.x,dy=p2.y-p1.y;
    if(clipTest(-dx,p1.x-XL,&u1,&u2))
	if(clipTest(dx,XR-p1.x,&u1,&u2))
	   if(clipTest(-dy,p1.y-YB,&u1,&u2))
	      if(clipTest(dy,YT-p1.y,&u1,&u2))
	      {
		  if(u2<1.0)
		  {
		      p2.x=p1.x+u2*dx;
		      p2.y=p1.y+u2*dy;
		  }
		  if(u1>0.0)
		  {
		      p1.x=p1.x+u1*dx;
		      p1.y=p1.y+u1*dy;
		  }
	      }
    moveto(p1.x,p1.y);lineto(p2.x,p2.y);
}

void main()
{
   int gdriver=DETECT,gmode;
   POINT p1,p2,p3,p4,p5,p6,p7,p8;
   p1.x=20;p1.y=150;p2.x=250;p2.y=130;p3.x=120;p3.y=60;p4.x=180;p4.y=300;
   p5.x=170;p5.y=40;p6.x=150;p6.y=200;p7.x=120;p7.y=200;p8.x=220;p8.y=130;

   initgraph(&gdriver,&gmode,"");
   setcolor(1);
   moveto(100,100);lineto(200,100);lineto(200,170);lineto(100,170);lineto(100,100);
   setcolor(2);
   C_S_Line(p1,p2,100,200,100,170);
   C_S_Line(p3,p4,100,200,100,170);
   setcolor(3);
   MPClip(p5,p6,100,200,100,170);
   setcolor(4);
   ClipParameter(p7,p8,100,200,100,170);
   getch();
   closegraph();
}