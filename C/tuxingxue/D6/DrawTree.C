#include "graphics.h"
#include "math.h"
double turn(double angle,double ANGLE)/*当前角度旋转*/
{
    ANGLE+=angle;
    ANGLE=ANGLE-(int)ANGLE+(int)ANGLE%360;
    return ANGLE;
}
void fractal(double gene[][2],double leng,double a,int n_gene,double *ANGLE,double *LPX,double *LPY)
{
    int i;double length;
    double x,y;
    double RADIAN;  /*弧度*/
    if(leng<=a)  /*递归结束条件, 当给定的发生器长度比其节数还小时结束*/
    {
	RADIAN=(*ANGLE)*3.1415926/180;
	x=(*LPX)+leng*cos(RADIAN);
	y=(*LPY)-leng*sin(RADIAN);
	moveto((*LPX),(*LPY));
	lineto(x,y);
	(*LPX)=x; (*LPY)=y;
    }
    else
    {
        for(i=0;i<n_gene;i++)  /*对组成发生器的每条线段进行递归处理*/
	{
	    (*ANGLE)=turn(gene[i][0],(*ANGLE));
	    if(-180.0!=gene[i][0])
		fractal(gene,gene[i][1]*leng/a,a,n_gene,ANGLE,LPX,LPY);
	    else  /*返回到树的主干上，对非树状图形，没有-180的转角*/
	    {
		length=gene[i][1]*leng/a;
		RADIAN=(*ANGLE)*3.1415926/180;
		(*LPX)+=length*cos(RADIAN);
		(*LPY)-=length*sin(RADIAN);
	    }
        }
    }
}
void DrawTree(double gene[][2]) /* gene为存储发生器的数组*/
{
    double END=1995.6; /*发生器的结束标志*/
    double a=0.0,c=0;
    int i=0,n_gene;  /*数组gene的第一维元素个数，即组成发生器的线段个数*/
    double leng0=400.0;  /*绘图总长度*/
    double LPX=120.0,LPY=200.0;  /*开始坐标*/
    double ANGLE=0.0,RADIAN=0.0;
    while(gene[i][0]!= END)
    {
	 ANGLE=turn(gene[i][0],ANGLE);
	 RADIAN=ANGLE*3.1415926/180;  /*角度化弧度*/
         a+=gene[i][1]*cos(RADIAN);  /*a为水平方向累加节数*/
	 c+=gene[i][1]*sin(RADIAN);  /*c为垂直方向累加节数*/
	 i++;
    }
    n_gene=i;
    a/=cos(atan(c/a));  /*a为总节数*/
    fractal(gene,leng0,a,n_gene,&ANGLE,&LPX,&LPY);
}
void main()
{
  int gdriver=DETECT,gmode;
  double END=1995.6;/*END为结束标志*/
  /*static double gene[][2]={{0.0,1.0},{85.0,1.0},{-170.0,1.0},{85.0,2.0},1995.6};*//*针叶树的树林*/
  /*分形的羊凿树叶*/
  static double gene[][2]={{ 0.0,  0.6}, {80.0,1.0},{-180.0,1.0},{20.0,1.0},{-180.0,1.0},
                    {-100.0,0.55},{80.0,0.9},{-180.0,0.9},{20.0,0.9},{-180.0,0.9},
                    {-100.0,0.5}, {80.0,0.8},{-180.0,0.8},{20.0,0.8},{-180.0,0.8},
                    {-100.0,0.45},{80.0,0.7},{-180.0,0.7},{20.0,0.7},{-180.0,0.7},
		    {-100.0,0.4}, {80.0,0.6},{-180.0,0.6},{20.0,0.6},{-180.0,0.6},
                    {-100.0,0.35},{80.0,0.5},{-180.0,0.5},{20.0,0.5},{-180.0,0.5},
                    {-100.0,0.3}, {80.0,0.4},{-180.0,0.4},{20.0,0.4},{-180.0,0.4},
                    {-100.0,0.25},{80.0,0.3},{-180.0,0.3},{20.0,0.3},{-180.0,0.3},
                    {-100.0,0.2}, {80.0,0.2},{-180.0,0.2},{20.0,0.2},{-180.0,0.2},
                    {-100.0,0.15},{80.0,0.1},{-180.0,0.1},{20.0,0.1},{-180.0,0.1},
		    {-100.0,0.1},1995.6};
  initgraph(&gdriver,&gmode,"");
  DrawTree(gene);/*gene为发生器,给出不同的gene就可画出不同的分形图形*/
  getch();
  closegraph();
}