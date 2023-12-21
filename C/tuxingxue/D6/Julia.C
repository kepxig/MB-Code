#include "graphics.h"
#include "math.h"
void julia(double x0,double y0,double xc,double yc,int sx,int sy,int Num)
{
    int i,k,KL=200;
    double s,BOX=0.01;
    int cx=320,cy=240;  /*绘图中点*/
    int col[][2]={{2,3},{4,6},{8,5},{16,2},{32,4},{64,1},{201,7}};
    static double x[201],y[201];
    x[0]=x0;y[0]=y0;
    for(k=1;k<=KL;k++)  /*计算复数数列*/
    {
        if(Num<29)
	{
	   /*二次函数*/
	   x[k]=x[k-1]*x[k-1]-y[k-1]*y[k-1]+xc;  /*实部*/
           y[k]=2*x[k-1]*y[k-1]+yc;  /*虚部*/
	}
	else
	{
           /*三次函数*/
	   x[k]=x[k-1]*x[k-1]*x[k-1]-3*x[k-1]*y[k-1]*y[k-1]+xc;
           y[k]=3*x[k-1]*x[k-1]*y[k-1]-y[k-1]*y[k-1]*y[k-1]+yc;
	}
        s=x[k]*x[k]+y[k]*y[k];
        if(s>=4.0)/*发散*/
	{
	   if(Num>=21 && Num<=28)  /*描画发散区域*/
	   {
	      i=0;
	      while(k>col[i][0] && k<=KL) i++;
	      putpixel(cx+sx,cy-sy,col[i][1]);
	   }
           return;
	}
    }
    if(s<4.0 && (Num<21 || Num>28))
    {
	/*非发散情况(收敛、振动、无秩序)*/
        for(k=1;k<=13;k++)   /*周期点数计算，根据点数着色*/
	{
	    /*从数列的最后项起若第k项落在以最后一项为中心+-BOX的小正方形内，则周期点数为k*/
	    if(fabs(x[KL]-x[KL-k])<BOX && fabs(y[KL]-y[KL-k])<BOX)
	    {
                putpixel(cx+sx,cy+sy,k);
		return;
	    }
	}
        /*无秩序用15号白色描画，周期点数14以上时也用白色*/
        putpixel(cx+sx,cy+sy,15);
    }
}

void DrawJulia(int Num)
{
    double a1,b1,a2,b2;  /*坐标变换系数*/
    double x0,y0,xc,yc;
    int cx=320,cy=240;  /*绘图中点*/
    int sx,sy,dx=192,dy=192;  /*dx,dy为绘图范围，在x方向+-dx个点，在y方向+-dy个点*/
    double x_min,x_max,y_min,y_max;
    /* x_min=-2.0;x_max=2.0;y_min=-2.0;y_max=2.0; //复数平面描画区域*/
    x_min=-1.5;x_max=1.5;y_min=-1.5;y_max=1.5; /*复数平面描画区域*/
    switch(Num)
    {
	/*下面4个为实数*/
	case 1: xc=-0.6; yc=0.0; break;
	case 2:	xc=-0.85; yc=0.0; break;
	case 3: xc=-1.1; yc=0.0; break;
	case 4: xc=-1.35; yc=0.0; break;

	/*下面18个为复数*/
	case 5: xc=-1.1; yc=0.2; break;
	case 6: xc=-0.1; yc=0.77; break;
	case 7: xc=0.3; yc=0.5; break;
	case 8: xc=-0.52; yc=0.55; break;
	case 9: xc=-1.15; yc=0.25; break;
	case 10: xc=0.12; yc=0.61; break;
	case 11: xc=-0.37; yc=0.61; break;
	case 12: xc=0.29; yc=0.57; break;
	case 13: xc=0.32; yc=0.57; break;
	case 14: xc=0.24; yc=0.54; break;
	case 15: xc=0.29; yc=0.54; break;
	case 16: xc=0.32; yc=0.54; break;
	case 17: xc=0.25; yc=0.5; break;
	case 18: xc=0.29; yc=0.49; break;
	case 19: xc=-0.2; yc=0.75; break;
	case 20: xc=0.24; yc=0.49; break;

	/*发散区域*/
	case 21: xc=0.38; yc=0.15; break;
	case 22: xc=-0.704; yc=0.28; break;
	case 23: x_min=-0.27; x_max=0.13; y_min=0.51; y_max=0.91; xc=-0.704; yc=0.28; break;
	case 24: x_min=-1.4; x_max=1.4; y_min=-1.1; y_max=1.1; xc=-1.27; yc=0.04; break;
	case 25: xc=-0.035; yc=0.795; break;
	case 26: x_min=-0.38; x_max=0.12; y_min=0.65; y_max=1.15; xc=-0.035; yc=0.795; break;
	case 27: xc=-0.6; yc=0.425; break;
	case 28: xc=-0.23; yc=0.67; break;

	/*三次函数*/
	case 29: xc=0.22; yc=0.96; break;
	case 30: xc=0.57; yc=0.24; break;
	case 31: xc=0.35; yc=0.69; break;
	case 32: xc=0.33; yc=0.66; break;
    }
    a1=(x_max-x_min)/(2*dx);
    b1=(x_max+x_min)/2;
    a2=(y_max-y_min)/(2*dy);
    b2=(y_max+y_min)/2;
    if(Num<21 || Num>28)
    {
        /*坐标轴的描画*/
        rectangle(cx-dx,cy-dy,cx+dx,cy+dy);
        for(sx=-dx+dx/4;sx<dx;sx+=dx/4)
	{
            moveto(cx+sx,cy-dy);
	    lineto(cx+sx,cy+dy);
	}
        for(sy=-dy+dy/4;sy<=dy;sy+=dy/4)
	{
            moveto(cx-dx,cy+sy);
	    lineto(cx+dx,cy+sy);
	}
    }
    for(sx=-dx;sx<=dx;sx++)
    {
	x0=a1*sx+b1;  /*x的初值*/
        for(sy=-dy;sy<=dy;sy++)
        {
	    y0=a2*sy+b2;  /*y的初值*/
	    julia(x0,y0,xc,yc,sx,sy,Num);  /*对区域内的所有点，调用julia1来决定着什么色*/
        }
    }
    printf("x_min=%5.1f\n",x_min);
    printf("x_max=%5.1f\n",x_max);
    printf("y_min=%5.1f\n",y_min);
    printf("y_max=%5.1f\n",y_max);
    printf("xc=%6.2f\n",xc);
    printf("yc=%6.2f\n",yc);
}
void main()
{
  int gdriver=DETECT,gmode;
  initgraph(&gdriver,&gmode,"");
  DrawJulia(28);/*input 1-32*/
  getch();
  closegraph();
}

