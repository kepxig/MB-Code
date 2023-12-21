
#include "graphics.h"
#define XLen 320
#define YLen 200
void ProjBoblique(int m_np,int m_ne,float x[20],float y[20],float z[20],int edge[40][2])
{
    int i,j,scale=25;
    float x1[20],z1[20];
    for(i=1;i<=m_np;i++)
    {
	x1[i]=x[i]-0.354*y[i];
	z1[i]=-0.354*y[i]+z[i];
	x1[i]=-x1[i]*scale+XLen;
	z1[i]=-z1[i]*scale+YLen;
    }
    for(j=0;j<m_ne;j++)
    {
	moveto((int)x1[edge[j][0]],(int)z1[edge[j][0]]);
	lineto((int)x1[edge[j][1]],(int)z1[edge[j][1]]);
    }
}

void ProjBortho(int m_np,int m_ne,float x[20],float y[20],float z[20],int edge[40][2])
{
    int i,j,scale=25;
    float x1[20],y1[20],z1[20];
    for(i=1;i<=m_np;i++)
    {
	x1[i]=0.935*x[i]-0.354*y[i];
	z1[i]=-0.118*x[i]-0.312*y[i]+0.943*z[i];
	x1[i]=-x1[i]*scale+XLen;
	z1[i]=-z1[i]*scale+YLen;
    }
    for(j=0;j<m_ne;j++)
    {
	moveto((int)x1[edge[j][0]],(int)z1[edge[j][0]]);
	lineto((int)x1[edge[j][1]],(int)z1[edge[j][1]]);
    }
}

void ProjIso(int m_np,int m_ne,float x[20],float y[20],float z[20],int edge[40][2])
{
    int i,j,scale=25;
    float x1[20],y1[20],z1[20];
    for(i=1;i<=m_np;i++)
    {
	x1[i]=0.707*(x[i]-y[i]);
	z1[i]=-0.408*(x[i]+y[i])+0.816*z[i];
	x1[i]=-x1[i]*scale+XLen;
	z1[i]=-z1[i]*scale+YLen;
    }
    for(j=0;j<m_ne;j++)
    {
	moveto((int)x1[edge[j][0]],(int)z1[edge[j][0]]);
	lineto((int)x1[edge[j][1]],(int)z1[edge[j][1]]);
    }
}

void ProjOne(int m_np,int m_ne,float x[20],float y[20],float z[20],int edge[40][2])
{
    float k=50.0,m=-8.0,n=-20.0,q=-0.1,scale=10.0;
    float x1[20],y1[20],z1[20],t[20];
    int i,j,n1,n2;
    for(i=1;i<=m_np;i++)
    {
	x[i]=x[i]+k; y[i]=y[i]+m; z[i]=z[i]+n;
	t[i]=q*y[i]+1.0;
	x1[i]=x[i]/t[i];z1[i]=z[i]/t[i];
	x1[i]=-x1[i]*scale+XLen+400;
	z1[i]=-z1[i]*scale+YLen-100;
    }
    for(i=0;i<m_ne;i++)
    {
	n1=edge[i][0];n2=edge[i][1];
	moveto((int)x1[n1],(int)z1[n1]);
	lineto((int)x1[n2],(int)z1[n2]);
    }
}

void ProjOrtho(int m_np,int m_ne,float x[20],float y[20],float z[20],int edge[40][2])
{
    float x1[20],y1[20],z1[20];
    int i,j,scale=8,n=20,k=20;
/*V*/
    for(i=1;i<=m_np;i++)
    {
	x1[i]=-x[i]*scale+XLen;z1[i]=-z[i]*scale+YLen;
    }
    for(j=0;j<m_ne;j++)
    {
	moveto((int)x1[edge[j][0]],(int)z1[edge[j][0]]);
	lineto((int)x1[edge[j][1]],(int)z1[edge[j][1]]);
    }
/*H*/
    for(i=1;i<=m_np;i++)
    {
	x1[i]=x[i];z1[i]=-y[i]-n;
	x1[i]=-x1[i]*scale+XLen;
	z1[i]=-z1[i]*scale+YLen;
    }
    for(j=0;j<m_ne;j++)
    {
	moveto((int)x1[edge[j][0]],(int)z1[edge[j][0]]);
	lineto((int)x1[edge[j][1]],(int)z1[edge[j][1]]);
    }
/*W*/
    for(i=1;i<=m_np;i++)
    {
	x1[i]=-y[i]-k;z1[i]=z[i];
	x1[i]=-x1[i]*scale+XLen;
	z1[i]=-z1[i]*scale+YLen;
    }
    for(j=0;j<m_ne;j++)
    {
	moveto((int)x1[edge[j][0]],(int)z1[edge[j][0]]);
	lineto((int)x1[edge[j][1]],(int)z1[edge[j][1]]);
    }
}

void ProjTwo(int m_np,int m_ne,float x[20],float y[20],float z[20],int edge[40][2])
{
    float x1[20],y1[20],z1[20],x2[20],y2[20],z2[20],t[20];
    float k=-8.0;
    float m=-6.0;
    float n=-10;
    float q=-0.1;
    float scale=8.0;
    int i,j;
    for(i=1;i<=m_np;i++)
    {
	x1[i]=0.866*x[i]-0.5*y[i];
	y1[i]=0.5*x[i]+0.866*y[i];
	z1[i]=z[i];
    }
    for(i=1;i<=m_np;i++)
    {
	x2[i]=x1[i]+k;
	y2[i]=y1[i]+m;
	z2[i]=z1[i]+n;
	t[i]=q*y2[i]+1.0;
	x2[i]=x2[i]/t[i];
	z2[i]=z2[i]/t[i];
	x2[i]=-x2[i]*scale+XLen;
	z2[i]=-z2[i]*scale+YLen;
    }
    for(j=0;j<m_ne;j++)
    {
	moveto((int)x2[edge[j][0]],(int)z2[edge[j][0]]);
	lineto((int)x2[edge[j][1]],(int)z2[edge[j][1]]);
    }
}

void main()
{
    int GraphDriver=0,GraphMode;

    int np,ne;
    float x[20],y[20],z[20];
    int edge[40][2];
    np=8;
    ne=12;
    x[1]=x[4]=x[5]=x[8]=0;  x[2]=x[3]=x[6]=x[7]=10;
    y[1]=y[2]=y[3]=y[4]=8;  y[5]=y[6]=y[7]=y[8]=0;
    z[1]=z[2]=z[5]=z[6]=0;  z[3]=z[4]=z[7]=z[8]=6;

    edge[0][0]=1;edge[0][1]=2;  edge[1][0]=2;edge[1][1]=3;
    edge[2][0]=3;edge[2][1]=4;  edge[3][0]=4;edge[3][1]=1;
    edge[4][0]=5;edge[4][1]=6;  edge[5][0]=6;edge[5][1]=7;
    edge[6][0]=7;edge[6][1]=8;  edge[7][0]=8;edge[7][1]=5;
    edge[8][0]=1;edge[8][1]=5;  edge[9][0]=4;edge[9][1]=8;
    edge[10][0]=2;edge[10][1]=6;edge[11][0]=3;edge[11][1]=7;

    initgraph(&GraphDriver,&GraphMode,"");
    /*ProjOrtho(np,ne,x,y,z,edge);*/
    /*ProjIso(np,ne,x,y,z,edge);*/
    /*ProjBortho(np,ne,x,y,z,edge);*/
    /*ProjBoblique(np,ne,x,y,z,edge);*/
    /*ProjOne(np,ne,x,y,z,edge);*/
    ProjTwo(np,ne,x,y,z,edge);
    getch();
    closegraph();
}