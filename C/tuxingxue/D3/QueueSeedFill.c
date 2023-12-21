#include"graphics.h"
#define NULL 0
typedef struct point{  int x,y;}POINT;
typedef struct QNode
{
    POINT Data;
    struct QNode *Next;
}QNode,*QPtr;
typedef struct
{
    QPtr Front;
    QPtr Rear;
}LinkQueue;
LinkQueue q;
void CreateQueue()
{
    q.Front=q.Rear=(QPtr)malloc(sizeof(QNode));
    q.Rear->Next=NULL;
}
POINT Dequeue()
{
    QNode *p;POINT x;
    p=q.Front;x=q.Front->Data;q.Front=q.Front->Next;free(p);
    return x;
}

void Enqueue(POINT x)
{
    QNode *p=(QPtr)malloc(sizeof(QNode));
    q.Rear->Next=p;q.Rear->Data=x;q.Rear=p;
}

int Empty()
{
    if( q.Front==q.Rear)return 1;
    else return 0;
}

void QueueSeedFill(int seedx, int seedy, int fcolor, int bcolor)
{
    int color;
    POINT pt,p,p1,p2,p3,p4;
    putpixel(seedx,seedy,fcolor);
    p.x=seedx;p.y=seedy;
    Enqueue(p);
    while(!Empty())
    {
	pt=Dequeue();
	color=getpixel(pt.x,pt.y-1);
	if(color!=bcolor && color!=fcolor)
	{
	    putpixel(pt.x,pt.y-1,fcolor);
	    p1.x=pt.x;p1.y=pt.y-1;
	    Enqueue(p1);
	}

	color=getpixel(pt.x,pt.y+1);
	if(color!=bcolor && color!=fcolor)
	{
	    putpixel(pt.x,pt.y+1,fcolor);
	    p2.x=pt.x;p2.y=pt.y+1;
	    Enqueue(p2);
	}

	color=getpixel(pt.x-1,pt.y);
	if(color!=bcolor && color!=fcolor)
	{
	    putpixel(pt.x-1,pt.y,fcolor);
	    p3.x=pt.x-1;p3.y=pt.y;
	    Enqueue(p3);
	}

	color=getpixel(pt.x+1,pt.y);
	if(color!=bcolor && color!=fcolor)
	{
	    putpixel(pt.x+1,pt.y,fcolor);
	    p4.x=pt.x+1;p4.y=pt.y;
	    Enqueue(p4);
	}
    }
}
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
void QSeedFill(int cnt,POINT *pts,int seedx,int seedy,int fcolor,int bcolor)
{
   POINT v1,v2;
   int i;
   for(i=0;i<cnt-1;i++)
   {
       v1=pts[i]; v2=pts[i+1];
       EdgeMark(v1.x,v1.y,v2.x,v2.y,bcolor);
   }
   QueueSeedFill(seedx,seedy,fcolor,bcolor);
}

void main()
{
   POINT pts[7];
   int gdriver=DETECT,gmode;
   pts[0].x=40;pts[0].y=10;
   pts[1].x=80;pts[1].y=40;
   pts[2].x=120;pts[2].y=20;
   pts[3].x=140;pts[3].y=70;
   pts[4].x=70;pts[4].y=100;
   pts[5].x=20;pts[5].y=60;
   pts[6].x=40;pts[6].y=10;

   initgraph(&gdriver,&gmode,"");
   QSeedFill(7,pts,75,80,2,3);
   getch();
}