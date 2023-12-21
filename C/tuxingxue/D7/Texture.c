
#include "graphics.h"
#include "math.h"
#define PI 3.1415926
typedef struct point{ int x,y;}POINT;
POINT screen(float x,float z,float R1,float R2,double a)
{
    POINT p;
    p.x=320-x; p.y=200-45+0.5*(R1+R2)/tan(a)-z;
    return p;
}
void rotxz(float *x,float *y,float *z)
{
    double xa=35,ya=0,za=0;
    double za1,xa1,ya1;
    float x1=*x,y1=*y,z1=*z;
    za1=PI*za/180; xa1=PI*xa/180; ya1=PI*ya/180;
    *x=x1*(cos(za1)*cos(ya1)-sin(za1)*sin(xa1)*sin(ya1))
      +y1*(-sin(za1)*cos(ya1)-cos(za1)*sin(xa1)*sin(ya1))
      +z1*cos(xa1)*sin(ya1);
    *y=x1*sin(za1)*cos(xa1)+y1*cos(za1)*cos(xa1)+z1*sin(xa1);
    *z=x1*(-cos(za1)*sin(ya1)-sin(za1)*sin(xa1)*cos(ya1))
      +y1*(sin(za1)*sin(ya1)-cos(za1)*sin(xa1)*cos(ya1))
      +z1*cos(xa1)*cos(ya1);
}
float vis(double fi1,double a)
{
    float x,y,z;
    x=cos(fi1); y=sin(fi1); z=-tan(a);
    rotxz(&x,&y,&z);
    return y;
}

void conter(float *fimin,float *fimax,double a)
{
    double fi1,fi2,fi;
    float n1,n2,vn;
    int i;
    for(i=0;i<360;i=i+5)
    {
	fi1=i*PI/180.0; fi2=(i+5)*PI/180.0;
	n1=vis(fi1,a); n2=vis(fi2,a);
        if(n1==0) *fimin=fi1;
        if(n2==0) *fimax=fi2;
        if((n1<0.0)&&(n2>0.0))
	{
	    for(;;)
	    {
		fi=0.5*(fi2+fi1);
		vn=vis(fi,a);
		if(vn<0.0) fi1=fi;
		if(vn>0.0) fi2=fi;
		if((vn>0.0)&&(vn<1E-6)) break;
	    }
	    *fimin=fi;
	}
        if((n1>0.0)&&(n2<0.0))
	{
	    for(;;)
	    {
		fi=0.5*(fi2+fi1);
		vn=vis(fi,a);
		if(vn>0.0)  fi1=fi;
		if(vn<0.0) fi2=fi;
		if((vn>0.0)&&(vn<1E-6)) break;
	    }
	    *fimax=fi;
	}
    }
    if(*fimin>*fimax) *fimin=-2*PI+*fimin;
}

void contour(double fi,float R1,float R2,double a)
{
    float x,y,z;POINT p;
    x=R1*cos(fi); y=R1*sin(fi); z=R1/tan(a);
    rotxz(&x,&y,&z);
    p=screen(x,z,R1,R2,a);
    moveto(p.x,p.y);
    x=R2*cos(fi); y=R2*sin(fi); z=R2/tan(a);
    rotxz(&x,&y,&z);
    p=screen(x,z,R1,R2,a);
    lineto(p.x,p.y);
}

void tfiger(float xp,float yp,float c0,float r0,double a,float *x,float *y,float *z,float *nx,float *ny,float *nz)
{
    float r;
    double c;
    r=sin(a)*sqrt(xp*xp+(r0/sin(a)+yp)*(r0/sin(a)+yp));
    c=c0+(atan(xp/(r/sin(a)+yp)))/sin(a);
    *x=r*cos(c); *y=r*sin(c); *z=r/tan(a);
    *nx=r*cos(c)/tan(a); *ny=r*sin(c)/tan(a); *nz=-r;
}
void TextureMap(float D,float R1,float R2,double a,int FColor)
{
    POINT p;
    float xp,yp,c0,r0;
    int i,j,k,k1,n;
    float A,E,F,x1,y1,x2,y2,d;
    float x,y,z;
    float nx,ny,nz;
    setcolor(FColor);
    r0=R1+(R2-R1)/3; c0=PI/2;
    for(k1=0;k1<2;k1++)
    {
	r0=R1+(R2-R1)/4+(R2-R1)*k1/2.5;
        for(k=0;k<3;k++)
	{
	    c0=PI/2+60*PI/180*(k-1);
	    for(i=0;i<=720;i=i+3)
	    {
		A=PI/360.0*i;
		E=D*(1+1/4*sin(12*A));
		F=E*(1+sin(4*A));
		x1=F*cos(A);   x2=F*cos(A+PI/5);
		y1=F*sin(A);   y2=F*sin(A+PI/5);
		d=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
		n=ceil(d);
		for(j=0;j<=n;j=j+1)
		{
		    if(n==0) break;
		    xp=x1+(x2-x1)*j/n;  yp=y1+(y2-y1)*j/n;
		    tfiger(xp,yp,c0,r0,a,&x,&y,&z,&nx,&ny,&nz);
		    rotxz(&x,&y,&z);
		    p=screen(x,z,R1,R2,a);
		    x=nx;y=ny;z=nz;
		    rotxz(&x,&y,&z);
		    nx=x;ny=y;nz=z;
		    if(j==0) moveto(p.x,p.y);
		    if(ny<0.0) moveto(p.x,p.y);
		    if(ny>0.0) lineto(p.x,p.y);
		}
	    }
	    for(i=0;i<=720;i=i+2)
	    {
		A=PI/360.0*i; E=D*(1+1/4*sin(12*A));
		F=E*(1+sin(4*A));
		xp=F*cos(A);  yp=F*sin(A);
		tfiger(xp,yp,c0,r0,a,&x,&y,&z,&nx,&ny,&nz);
		rotxz(&x,&y,&z);
		p=screen(x,z,R1,R2,a);
		x=nx;y=ny;z=nz;
		rotxz(&x,&y,&z);
		nx=x;ny=y;nz=z;
		if(i==0)  moveto(p.x,p.y);
		if(ny<0.0) moveto(p.x,p.y);
		else lineto(p.x,p.y);
	    }
	    for(i=0;i<=720;i=i+1)
	    {
		A=PI/360.0*i; E=D*(1+1/4*sin(12*A));
		F=E*(1+sin(4*A));
		xp=F*cos(A+PI/5);  yp=F*sin(A+PI/5);
		tfiger(xp,yp,c0,r0,a,&x,&y,&z,&nx,&ny,&nz);
		rotxz(&x,&y,&z);
		p=screen(x,z,R1,R2,a);
		x=nx;y=ny;z=nz;
		rotxz(&x,&y,&z);
		nx=x;ny=y;nz=z;
		if(i==0) moveto(p.x,p.y);
		if(ny<0.0) moveto(p.x,p.y);
		else lineto(p.x,p.y);
	    }
	    for(i=0;i<=360;i=i+2)
	    {
		A=PI/180.0*i;
		xp=2.2*D*cos(A); yp=2.2*D*sin(A);
		tfiger(xp,yp,c0,r0,a,&x,&y,&z,&nx,&ny,&nz);
		rotxz(&x,&y,&z);
		p=screen(x,z,R1,R2,a);
		x=nx;y=ny;z=nz;
		rotxz(&x,&y,&z);
		nx=x; ny=y;nz=z;
		if(i==0) moveto(p.x,p.y);
		if(ny<0.0) moveto(p.x,p.y);
		else lineto(p.x,p.y);
	    }
	}
    }
}

void FlowerVase(float D,float R1,float R2,double a,int Color,int FColor)
{
    int i,sx1,sy1;
    float ny1=-1;
    double A; POINT p;
    float fimin=0,fimax=0;
    float x,y,z;
    float nx,ny,nz;

    a=a*PI/180.0;
    setcolor(Color);
    for(i=0;i<=360;i=i+2)
    {
	A=i*2*PI/360;
        x=R2*cos(A);y=R2*sin(A);z=R2/tan(a);
        rotxz(&x,&y,&z);
        p=screen(x,z,R1,R2,a);
        if(i==0) moveto(p.x,p.y);
        lineto(p.x,p.y);
    }
    conter(&fimin,&fimax,a);
    for(i=0;i<=180;i=i+4)
    {
	A=fimin+i*(fimax-fimin)/180;
	x=R1*cos(A);y=R1*sin(A);z=R1/tan(a);
	rotxz(&x,&y,&z);
	p=screen(x,z,R1,R2,a);
	if(i==0) moveto(p.x,p.y);
	lineto(p.x,p.y);
    }
    for(i=0;i<=360;i=i+2)
    {
	A=2*PI*i/360;
	x=R1*cos(A);y=R1*sin(A);z=R1/tan(a);
	rotxz(&x,&y,&z);
	p=screen(x,z,R1,R2,a);
	moveto(p.x,p.y);
	x=R1*cos(A);y=R1*sin(A);z=R1/tan(a)-35;
	rotxz(&x,&y,&z);
	p=screen(x,z,R1,R2,a);
	nx=cos(A);ny=sin(A);nz=0;
	x=nx;y=ny;z=nz;
	rotxz(&x,&y,&z);
	nx=x;ny=y;nz=z;
	if(ny>0.0) lineto(p.x,p.y);
	if((ny1>=0.0)&&(ny>=0.0)) {moveto(sx1,sy1);lineto(p.x,p.y);}
	sx1=p.x,sy1=p.y;ny1=ny;
    }
    contour(fimin,R1,R2,a);
    contour(fimax,R1,R2,a);
    TextureMap(D,R1,R2,a,FColor);
}

void main()
{
    int gdriver=DETECT,gmode;
    initgraph(&gdriver,&gmode,"");
    FlowerVase(28,90,180,15,1,4);
    getch();
    closegraph();
}
