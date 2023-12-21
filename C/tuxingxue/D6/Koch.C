#include "graphics.h"
#include "math.h"
double turn(double angle,double ANGLE)/*当前角度旋转*/
{
    ANGLE+=angle;
    ANGLE=ANGLE-(int)ANGLE+(int)ANGLE%360;
    return ANGLE;
}
void Koch(double leng,int n,int N,double *LPX,double *LPY,double *ANGLE)
{
    double x,y, RADIAN=(*ANGLE)*3.1415926/180;/*角度化弧度*/
    if(n>=N)
    {
	x=(*LPX)+leng*cos(RADIAN); y=(*LPY)-leng*sin(RADIAN);
        moveto((*LPX),(*LPY)); lineto(x,y);
        (*LPX)=x; (*LPY)=y;
    }
    else
    {
	Koch(leng/3,n+1,N,LPX,LPY,ANGLE);
        (*ANGLE)=turn(60.0,(*ANGLE));  Koch(leng/3,n+1,N,LPX,LPY,ANGLE);
        (*ANGLE)=turn(-120.0,(*ANGLE)); Koch(leng/3,n+1,N,LPX,LPY,ANGLE);
        (*ANGLE)=turn(60.0,(*ANGLE));  Koch(leng/3,n+1,N,LPX,LPY,ANGLE);
    }
}
void main()
{
    int gdriver=DETECT,gmode;
    double LPX=120.0,LPY=240.0;/*初始坐标*/
    double ANGLE=0.0;
    initgraph(&gdriver,&gmode,"");
    Koch(400.0,0,6,&LPX,&LPY,&ANGLE);
    getch();
    closegraph();
}
