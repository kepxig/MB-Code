#include<stdio.h>
#include<graphics.h>
#include<string.h>
#include<math.h>
#define Scale 1.35

void  DrawFace(int F,int Fc[30][11],float St[50][3],float Rol,float DE,
float Aux1,float Aux2,float Aux3,float Aux4,float Aux5,float Aux6,
float Aux7,float Aux8)
{
    float XObs,YObs,ZObs,XProj,YProj;
    int XScreen,YScreen;
    int S,NS,No;
    float X,Y,Z,X0,Y0,Z0;
    int MaxX=getmaxx();
    int MaxY=getmaxy();
    NS=Fc[F][0];
    for(S=1;S<=NS;S++)
    {
        No=Fc[F][S];
        X=St[No][1];
        Y=St[No][2];
        Z=St[No][3];
        XObs=-X*Aux1+Y*Aux3;
        YObs=-X*Aux5-Y*Aux6+Z*Aux4;
	ZObs=-X*Aux7-Y*Aux8-Z*Aux2+Rol;
	XProj=DE*XObs/ZObs;
	YProj=DE*YObs/ZObs;
        XScreen=floor(0.5+XProj*Scale+MaxX/2);
        YScreen=floor(0.5+MaxY/2-YProj);
        if(S==1)
        {
            moveto(XScreen,YScreen);
	    X0=XScreen;
	    Y0=YScreen;
        }
        else
            lineto(XScreen,YScreen);

    }
    lineto(X0,Y0);
}

void DrawObject(int Fc[30][11],float St[50][3],int NF,float Rol,float Theta,
float Phi,float DE,int Dot)
{
    float Th,Ph,Aux1,Aux2,Aux3,Aux4,Aux5,Aux6,Aux7,Aux8;
    int F,St1,St2,St3;
    float P1,P2,P3,Q1,Q2,Q3;
    float v1,v2,v3,n1,n2,n3;
    float O1,O2,O3,SProduct;
    Th=3.1415926*Theta/180;
    Ph=3.1415926*Phi/180;
    Aux1=sin(Th);
    Aux2=sin(Ph);
    Aux3=cos(Th);
    Aux4=cos(Ph);
    Aux5=Aux3*Aux2;
    Aux6=Aux1*Aux2;
    Aux7=Aux3*Aux4;
    Aux8=Aux1*Aux4;
    O1=Rol*Aux7;
    O2=Rol*Aux8;
    O3=Rol*Aux2;
    for(F=1;F<=NF;F++)
    {
       St1=Fc[F][1];St2=Fc[F][2]; St3=Fc[F][3];
       v1=O1-St[St1][1];
       v2=O2-St[St1][2];
       v3=O3-St[St1][3];
       P1=St[St2][1]-St[St1][1];
       P2=St[St2][2]-St[St1][2];
       P3=St[St2][3]-St[St1][3];
       Q1=St[St3][1]-St[St1][1];
       Q2=St[St3][2]-St[St1][2];
       Q3=St[St3][3]-St[St1][3];
       n1=P2*Q3-Q2*P3;
       n2=P3*Q1-Q3*P1;
       n3=P1*Q2-Q1*P2;
       SProduct=v1*n1+v2*n2+v3*n3;
       if(SProduct>0.0)
       {
          setlinestyle(SOLID_LINE,0,NORM_WIDTH);
	  DrawFace(F,Fc,St,Rol,DE,Aux1,Aux2,Aux3,Aux4,Aux5,Aux6,Aux7,Aux8);
       }
       else if(Dot==1)
       {
          setlinestyle(DOTTED_LINE,0,NORM_WIDTH);
	  DrawFace(F,Fc,St,Rol,DE,Aux1,Aux2,Aux3,Aux4,Aux5,Aux6,Aux7,Aux8);
        }
    }
}

void Polyhedron(int pColor)
{
    int NF,Fc[30][11],MaxX,MaxY;
    float St[50][3];
    MaxX=getmaxx();
    MaxY=getmaxy();
    setcolor(pColor);
    setviewport(0,0,MaxX,MaxY,1);
    St[1][1]=40;St[1][2]=54;St[1][3]=-40;
    St[2][1]=40;St[2][2]=54;St[2][3]=0;
    St[3][1]=40;St[3][2]=-54;St[3][3]=0;
    St[4][1]=40;St[4][2]=-54;St[4][3]=-40;
    St[5][1]=-40;St[5][2]=-54;St[5][3]=-40;
    St[6][1]=-40;St[6][2]=54;St[6][3]=-40;
    St[7][1]=-40;St[7][2]=54;St[7][3]=0;
    St[8][1]=0;St[8][2]=34;St[8][3]=40;
    St[9][1]=0;St[9][2]=-34;St[9][3]=40;
    St[10][1]=-40;St[10][2]=-54;St[10][3]=0;
    NF=9;
    Fc[1][0]=4;Fc[1][1]=1;Fc[1][2]=2;Fc[1][3]=3;Fc[1][4]=4;
    Fc[2][0]=4;Fc[2][1]=1;Fc[2][2]=6;Fc[2][3]=7;Fc[2][4]=2;
    Fc[3][0]=3;Fc[3][1]=2;Fc[3][2]=7;Fc[3][3]=8;
    Fc[4][0]=4;Fc[4][1]=2;Fc[4][2]=8;Fc[4][3]=9;Fc[4][4]=3;
    Fc[5][0]=4;Fc[5][1]=1;Fc[5][2]=4;Fc[5][3]=5;Fc[5][4]=6;
    Fc[6][0]=4;Fc[6][1]=7;Fc[6][2]=10;Fc[6][3]=9;Fc[6][4]=8;
    Fc[7][0]=3;Fc[7][1]=3;Fc[7][2]=9;Fc[7][3]=10;
    Fc[8][0]=4;Fc[8][1]=10;Fc[8][2]=5;Fc[8][3]=4;Fc[8][4]=3;
    Fc[9][0]=4;Fc[9][1]=5;Fc[9][2]=10;Fc[9][3]=7;Fc[9][4]=6;
    DrawObject(Fc,St,NF,800.0,330,30,1000,1);
}
void main()
{
    int ErrorCode,GraphDriver,GraphMode;
    GraphDriver=0;
    initgraph(&GraphDriver,&GraphMode,"");
    Polyhedron(1);
    getch();
    closegraph();
}


