#include "graphics.h"
typedef struct point {  int x,y;}POINT;
void Parabola(POINT *p,int n)
{
     int x,y,i,j,k=10;
     double t1,t2,t3,t,a,b,c,d;
     p[n].x=p[n-1].x;p[n].y=p[n-1].y;
     t=0.5/k;
     moveto(p[1].x,p[1].y);
     for(i=1;i<n-1;i++)
     {
	 for(j=1;j<k;j++)
	 {
	      t1=j*t;t2=t1*t1;t3=t2*t1;
	      a=4.0*t2-t1-4.0*t3; b=1.0-10.0*t2+12.0*t3;
	      c=t1+8.0*t2-12.0*t3; d=4.0*t3-2.0*t2;
	      x=(int)(a*p[i-1].x+b*p[i].x+c*p[i+1].x+d*p[i+2].x);
	      y=(int)(a*p[i-1].y+b*p[i].y+c*p[i+1].y+d*p[i+2].y);
	      lineto(x,y);
	 }
	 lineto(p[i+1].x,p[i+1].y);
     }
}
double powi(double v,int k)
{
    int i;
    double temp=1.0;
    if(k==0 || v==0)return 1;
    else
    {
	for(i=1;i<=k;i++)
          temp=temp*v;
    }
    return temp;
}
long fac(int m)
{
    int i;
    long temp=1;
    if(m==0)return 1;
    else
    {
	for(i=2;i<=m;i++)
	    temp=temp*i;
    }
    return temp;
}
void Bezier(POINT *p,int n)
{
     int x,y,i,j,k=100;
     double t,t1,u,v;
     double temp,temp1,temp2,bi;
     t=1.0/k;
     moveto(p[0].x,p[0].y);
     for(j=1;j<k;j++)
     {
	 t1=j*t;u=t1;v=1-u;x=0;y=0;
	 for(i=0;i<=n;i++)
	 {
	     temp=(double)fac(n)/fac(i)/fac(n-i);
	     temp1=powi(u,i);temp2=powi(v,n-i);
	     bi=temp*temp1*temp2;
	     x=x+bi*p[i].x;y=y+bi*p[i].y;
	 }
	 lineto(x,y);
     }
     lineto(p[n].x,p[n].y);
}

void BSpLine(POINT *p, int n)
{
    int x,y,i,j,k=1000;
    double t,t1,t2,t3,a,b,c,d;
    t=1.0/k;
    p[n].x=2*p[n-1].x-p[n-2].x;
    p[n].y=2*p[n-1].y-p[n-2].y;
    moveto(p[1].x,p[1].y);
    for(i=1;i<n-1;i++)
    {
	for(j=1;j<=k;j++)
	{
	    t1=j*t;
	    t2=t1*t1;
	    t3=t2*t1;
	    a=(3*t2-t3-3*t1+1)/6;
	    b=(3*t3-6*t2+4)/6;
	    c=(3*t2-3*t3+3*t1+1)/6;
	    d=t3/6;
	    x=(int)(a*p[i-1].x+b*p[i].x+c*p[i+1].x+d*p[i+2].x);
	    y=(int)(a*p[i-1].y+b*p[i].y+c*p[i+1].y+d*p[i+2].y);
	    lineto(x,y);
	}
    }
}
void CardinalSpLine(POINT *p,int n,float tension)
{
    int x,y,i,j,k=1000;
    double t,t1,t2,t3,a,b,c,d,s;
    t=1.0/k;s=(1.0-tension)/2.0;
    p[n].x=2*p[n-1].x-p[n-2].x;
    p[n].y=2*p[n-1].y-p[n-2].y;
    moveto(p[1].x,p[1].y);
    for(i=1;i<n-1;i++)
    {
	for(j=1;j<=k;j++)
	{
	    t1=j*t;
	    t2=t1*t1;
	    t3=t2*t1;
	    a=-s*t3+2*s*t2-s*t1;
	    b=(2-s)*t3+(s-3)*t2+1;
	    c=(s-2)*t3+(3-2*s)*t2+s*t1;
	    d=s*t3-s*t2;
	    x=(int)(a*p[i-1].x+b*p[i].x+c*p[i+1].x+d*p[i+2].x);
	    y=(int)(a*p[i-1].y+b*p[i].y+c*p[i+1].y+d*p[i+2].y);
	    lineto(x,y);
	}
    }
}
void main()
{
    int n=5,gdriver=DETECT,gmode;
    POINT ps[4];ps[0].x=50;ps[0].y=300;
    ps[1].x=50;ps[1].y=300;ps[2].x=150;ps[2].y=50;
    ps[3].x=250;ps[3].y=300;ps[4].x=350;ps[4].y=50;
    initgraph(&gdriver,&gmode,"");
    setcolor(1);
    moveto(ps[0].x,ps[0].y);
    lineto(ps[1].x,ps[1].y);
    lineto(ps[2].x,ps[2].y);
    lineto(ps[3].x,ps[3].y);
    setcolor(2);
    Parabola(ps,n);
    setcolor(3);
    CardinalSpLine(ps,n,0.5);
    setcolor(4);
    Bezier(ps,n-1);
    setcolor(5);
    BSpLine(ps,n);
    getch();
    closegraph();
}