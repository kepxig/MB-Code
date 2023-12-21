#include "graphics.h"
#include "math.h"
void MSB(cxmin,cxmax,cymin,cymax,nmax)
float cxmin,cxmax,cymin,cymax;  /*复平面C实虚部变化范围*/
int nmax;  /*最大迭代次数*/
{
    float sx=500.0,sy=450.0;  /*要显示的图像大小尺寸*/
    float cx,cy,x,y,xx,yy,dx,dy,z,L=4.0;
    int i,j,n,color;
    dx=(cxmax-cxmin)/sx; dy=(cymax-cymin)/sy;
    for(i=0;i<sx;i++)
    {
       cx=cxmin+i*dx;
       for(j=0;j<sy;j++)
       {
	  cy=cymin+j*dy; x=0;y=0;
	  for(n=0;n<nmax;n++)
	  {
	      xx=x*x-y*y+cx; yy=2*x*y+cy; z=xx+yy;
	      if(fabs(z)>L)break;
	      x=xx;y=yy;
	  }
	  color=n%16; putpixel(i+50,j+40,color);  /*50,40为画图起点*/
       }
    }
}
main()
{
    int gdriver=DETECT,gmode;
    initgraph(&gdriver,&gmode,"");
    MSB(-2.5,1.5,-1.8,2.2,100); /*x的取值为-2.5至1.5，y取值为-1.8至2.2*/
    getch();
    closegraph();
}
