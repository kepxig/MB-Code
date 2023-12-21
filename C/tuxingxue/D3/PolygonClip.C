#include "graphics.h"
#define  LEFT 1
#define  RIGHT  2
#define  BOTTOM 4
#define  TOP 8
typedef struct point { int x,y;} POINT;
typedef struct tRes
{
   int yes,isIn;
   POINT pout;
}Res;
void Encode (int x,int y,int *code,int XL,int XR,int YB,int YT)
{
    int c=0;
    if(x<XL) c=c|LEFT;
    else if(x>XR) c=c|RIGHT;
    if (y<YB) c=c|BOTTOM;
    else if (y>YT) c=c|TOP;
    (*code)=c;
}
void ClipEncodePolygon(POINT ps[50],int n,int XL,int XR,int YB,int YT)
{
    POINT tp[50];
    int i,j,k=0,m;
    int code1,code2,code;
    int x,y;
    for(i=0;i<n-1;i++)
    {
	Encode(ps[i].x,ps[i].y,&code1,XL,XR,YB,YT);
	Encode(ps[i+1].x,ps[i+1].y,&code2,XL,XR,YB,YT);
	code=code1;m=i;
	for(j=0;j<2;j++)
	{
	   if((code1 & code2)!=0)
	   {
	       switch(code)
	       {
		  case 1:x=XL;y=ps[m].y;break;
		  case 2:x=XR;y=ps[m].y;break;
		  case 4:x=ps[m].x;y=YB;break;
		  case 5:x=XL;y=YB;break;
		  case 6:x=XR;y=YB;break;
		  case 8:x=ps[m].x;y=YT;break;
		  case 9:x=XL;y=YT;break;
		  case 10:x=XR;y=YT;break;
	       }
	       tp[k].x=x;tp[k].y=y;k++;
	   }
	   else if((code1 & code2)==0)
	   {
	       if(code==0)
	       {
		  tp[k]=ps[m];k++;
	       }
	       else if ((LEFT & code) !=0)
	       {
		  x=XL;
		  y=ps[i].y+(ps[i+1].y-ps[i].y)*(XL-ps[i].x)/(ps[i+1].x-ps[i].x);
		  if(y>YB && y<YT){tp[k].x=x;tp[k].y=y;k++;}
	       }
	       else if((TOP & code)!=0)
	       {
		  y=YT;
		  x=ps[i].x+(ps[i+1].x-ps[i].x)*(YT-ps[i].y)/(ps[i+1].y-ps[i].y);
		  if(x>XL && x<XR){tp[k].x=x;tp[k].y=y;k++;}
	       }
	       else if((RIGHT & code)!=0)
	       {
		  x=XR;
		  y=ps[i].y+(ps[i+1].y-ps[i].y)*(XR-ps[i].x)/(ps[i+1].x-ps[i].x);
		  if(y>YB && y<YT){tp[k].x=x;tp[k].y=y;k++;}
	       }
	       else if((BOTTOM & code) != 0)
	       {
		  y=YB;
		  x=ps[i].x+(ps[i+1].x-ps[i].x)*(YB-ps[i].y)/(ps[i+1].y-ps[i].y);
		  if(x>XL && x<XR){tp[k].x=x;tp[k].y=y;k++;}
	       }
	   }
	   code=code2;m++;
	}
    }
    moveto(tp[0].x,tp[0].y);
    for(i=1;i<k;i++) lineto(tp[i].x,tp[i].y);
}

Res TestIntersect(int edge,int type,POINT p1,POINT p2)
{
    float dx,dy,m;
    Res res;int isIn=0,yes=0;POINT pout;
    dy=p2.y-p1.y;dx=p2.x-p1.x;m=dy/dx;
    switch(type)
    {
    case 1:  /*right*/
	if(p2.x<=edge){isIn=1;if(p1.x>edge)(yes)=1;}
	else if(p1.x<=edge)yes=1;break;
    case 2:  /*bottom*/
	if(p2.y>=edge){isIn=1;if(p1.y<edge)yes=1;}
	else if(p1.y>=edge)yes=1;break;
    case 3:  /*left*/
	if(p2.x>=edge){isIn=1;if(p1.x<edge)yes=1;}
	else if(p1.x>=edge)yes=1;break;
    case 4:  /*top*/
	if(p2.y<=edge){isIn=1;if(p1.y>edge)yes=1;}
	else if(p1.y<=edge)yes=1;
    default: break;
    }
    if(yes)
    {
	if((type==1) || (type==3))
	{   pout.x=edge;pout.y=p1.y+m*(pout.x-p1.x);}
	if((type==2) || (type==4))
	{   pout.y=edge;pout.x=p1.x+(pout.y-p1.y)/m;}
    }
    res.isIn=isIn;res.yes=yes;res.pout=pout;
    return res;
}

int clipSingleEdge(int edge,int type,int nin,POINT pin[50],POINT pout[50])
{
    int i,k=0;POINT p;Res res;
    p.x=pin[nin-1].x;p.y=pin[nin-1].y;
    for(i=0;i<nin;i++)
    {
	res=TestIntersect(edge,type,p,pin[i]);
	if(res.yes)
	{   pout[k].x=res.pout.x;pout[k].y=res.pout.y;k++;}
	if(res.isIn)
	{   pout[k].x=pin[i].x;pout[k].y=pin[i].y;k++;}
	p.x=pin[i].x;p.y=pin[i].y;
    }
    return k;
}

void ClipEdgePolygon(POINT ps[50],int n,int XL,int XR,int YB,int YT)
{
    int i,n1=0,n2=0;
    POINT pt[50];
    n1=clipSingleEdge(XR,1,n,ps,pt);
    n2=clipSingleEdge(YB,2,n1,pt,ps);
    n1=clipSingleEdge(XL,3,n2,ps,pt);
    n2=clipSingleEdge(YT,4,n1,pt,ps);

    moveto(ps[0].x,ps[0].y);
    for(i=1;i<n2;i++) lineto(ps[i].x,ps[i].y);
}

void main()
{
   int gdriver=DETECT,gmode;
   POINT p[10],q[10];
   p[0].x=120;p[0].y=150;p[1].x=170;p[1].y=40;
   p[2].x=220;p[2].y=170;p[3].x=350;p[3].y=180;
   p[4].x=230;p[4].y=330;p[5].x=180;p[5].y=240;
   p[6].x=120;p[6].y=150;

   q[0].x=125;q[0].y=155;q[1].x=175;q[1].y=45;
   q[2].x=225;q[2].y=175;q[3].x=355;q[3].y=185;
   q[4].x=235;q[4].y=335;q[5].x=185;q[5].y=245;
   q[6].x=125;q[6].y=155;

   initgraph(&gdriver,&gmode,"");
   setcolor(1);
   moveto(100,100);lineto(300,100);lineto(300,260);lineto(100,260);lineto(100,100);
   setcolor(2);
   ClipEncodePolygon(q,7,100,300,100,260);
   setcolor(4);
   ClipEdgePolygon(p,7,100,300,100,260);
   getch();
   closegraph();
}