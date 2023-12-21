#include "graphics.h"
#include "math.h"
#define PI 3.1415926
#define MaxX 640
#define MaxY 480
#define Scale 1.35
int HMax[640],HMin[640];

float F(float X,float Y)
{
    float w1,w2,w3,FV;
    w1=(X-2.0)/35.8; w2=(Y-1.0)/32.0; w3=-(w1*w1+w2*w2)/2;
    FV=1000000.0*exp(w3)/(2*3.1415926*35.8*32.0);
    return FV;
}
void Horizon(int x1,int y1,int x2,int y2/*,int HMax[640],int HMin[640]*/)
{
    int dX,XX,YY;
    float slope;
    if(x2>x1)dX=1;
    else if(x2==x1)dX=0;
    else dX=-1;
    if(dX==0)
    {
        HMax[x2+1]=(HMax[x2]>y2)?HMax[x2]:y2;
        HMin[x2+1]=(HMin[x2]<y2)?HMin[x2]:y2;
    }
    else
    {
        slope=(y2-y1)/(x2-x1);
        for(XX=x2+1;XX<=x1;++XX)
	{
            YY=slope*(XX-x1)+y1;
	    HMax[XX]=(HMax[XX]>YY)?HMax[XX]:YY;
	    HMin[XX]=(HMin[XX]<YY)?HMin[XX]:YY;
	}
    }
}
void Intersect(int x1,int y1,int x2,int y2,int ty1,int ty2,int *Xi,int *Yi)
{
    float Den,Xii,Yii;
    if(x2-x1==0)
    {
        Xii=x2;Yii=ty2;
    }
    else
    {
        Den=y2-y1-ty2+ty1;
        if(Den!=0)
	{
            Xii=(x1*(y2-ty2)+x2*(ty1-y1))/Den;
            Yii=(y2*ty1-y1*ty2)/Den;
	}
        else
	{
	    Xii=x2;Yii=y2;
	}
    }
    *Xi=(int)(Xii+0.5);*Yi=(int)(Yii+0.5);
}
void ProbSurf(float X1,float Y1,float X2,float Y2,float S,float Rol,float DE,
	float Theta,float Phi,int LNo,int PNo)
{
    float Aux,Th,Ph;
    float Aux1,Aux2,Aux3,Aux4,Aux5,Aux6,Aux7,Aux8;
    float XObs,YObs,ZObs,XProj,YProj;
    float X,Y,Z,IncX,IncY,EchX,EchY;
    float F1,F2,F3,F4;
    int i,Ln,Pt,XPre,YPre,VisPre,VisCur,XCur,YCur;
    int Xd=-1,Yd=-1,Xg=-1,Yg=-1;
    int Xi,Yi;
    IncX=(X2-X1)/PNo;IncY=(Y2-Y1)/LNo;
    F1=1E37;F2=-1E37;F3=1E37;F4=-1E37;
    for(i=0;i<=MaxX;++i){HMax[i]=0;HMin[i]=MaxY;}
    if((Theta<0)||(Theta>180))
    {
	Aux=X1;X1=X2;X2=Aux;IncX=-IncX;
	Aux=Y1;Y1=Y2;Y2=Aux;IncY=-IncY;
    }
    Th=PI*Theta/180.0;  Ph=PI*Phi/180.0;
    Aux1=sin(Th);Aux2=sin(Ph);
    Aux3=cos(Th);Aux4=cos(Ph);
    Aux5=Aux3*Aux2;Aux6=Aux1*Aux2;
    Aux7=Aux3*Aux4;Aux8=Aux1*Aux4;

    for(Ln=0;Ln<=LNo;++Ln)
    {
       Y=Y2-Ln*IncY;
       for(Pt=0;Pt<=PNo;++Pt)
       {
          X=X1+Pt*IncX;
          Z=F(X,Y);
          XObs=-X*Aux1+Y*Aux3;
          YObs=-X*Aux5-Y*Aux6+Z*Aux4;
          XProj=S*XObs;YProj=S*YObs;
          if(XProj<F1)F1=XProj;
          if(XProj>F2)F2=XProj;
          if(YProj<F3)F3=YProj;
          if(YProj>F4)F4=YProj;
       }
    }
    EchX=MaxX/(F2-F1);
    EchY=MaxY/(F4-F3);
    if(EchX<EchY)EchY=EchX;
    else EchX=EchY;

    for(Ln=0;Ln<=LNo;++Ln)
    {
       Y=Y2-Ln*IncY;X=X1;Z=F(X,Y);
       XObs=-X*Aux1+Y*Aux3;
       YObs=-X*Aux5-Y*Aux6+Z*Aux4;
       XProj=S*XObs;YProj=S*YObs;
       XPre=0.5+(XProj-F1)*EchX;
       YPre=0.5+(YProj-F3)*EchY;
       if(Xd!=-1)Horizon(Xd,Yd,XPre,YPre/*,HMax,HMin*/);
       Xd=XPre;Yd=YPre;
       if((YPre<HMax[XPre])&&(YPre>HMin[XPre]))VisPre=0;
       else if(YPre>=HMax[XPre])VisPre=1;
       else VisPre=-1;
       for(Pt=0;Pt<=PNo;++Pt)
       {
	   X=X1+Pt*IncX;Z=F(X,Y);
	   XObs=-X*Aux1+Y*Aux3;
	   YObs=-X*Aux5-Y*Aux6+Z*Aux4;
           XProj=S*XObs;YProj=S*YObs;
	   XCur=0.5+(XProj-F1)*EchX;
	   YCur=0.5+(YProj-F3)*EchY;
	   if((YCur<HMax[XCur])&&(YCur>HMin[XCur]))VisCur=0;
	   else if(YCur>=HMax[XCur])VisCur=1;
	   else VisCur=-1;
	   if((HMax[XCur]==0)||(HMax[XCur]==MaxY)) VisCur=VisPre;
	   if(VisCur==VisPre)
	   {
               if((VisCur==1)||(VisCur==-1))
		{
		   if(0<=XCur)
		      line(XPre,MaxY-60-YPre,XCur,MaxY-60-YCur);
		   else if(0<=YCur)
		      line(XPre,MaxY-60-YPre,XPre,MaxY-60-YCur);
		   else
		      line(XPre,MaxY-60-YPre,XPre,MaxY-60-YPre);
		   Horizon(XPre,YPre,XCur,YCur/*,HMax,HMin*/);
		}
	   }
	   else
	   {
	       if(VisCur==0)
	       {
		   if(VisPre==1)
		   {
		       Intersect(XPre,YPre,XCur,YCur,HMax[XPre],HMax[XCur],&Xi,&Yi);
		   }
		   else
		   {
		       Intersect(XPre,YPre,XCur,YCur,HMin[XPre],HMin[XCur],&Xi,&Yi);
		   }
		   if(0<=Xi)
		       line(XPre,MaxY-60-YPre,Xi,MaxY-60-Yi);
		   else if(0<=Yi)
		       line(XPre,MaxY-60-YPre,XPre,MaxY-60-Yi);
		   else
		       line(XPre,MaxY-60-YPre,XPre,MaxY-60-YPre);
		   Horizon(XPre,YPre,Xi,Yi/*,HMax,HMin*/);
	       }
	       else
	       {
		   if(VisCur==1)
		   {
		       if(VisPre==0)
			{
			   Intersect(XPre,YPre,XCur,YCur,HMax[XPre],HMax[XCur],&Xi,&Yi);
			   if(0<=Xi)
			      line(Xi,MaxY-60-Yi,XCur,MaxY-60-YCur);
			   else if(0<=Yi)
			      line(XCur,MaxY-60-Yi,XCur,MaxY-60-YCur);
			   else
			      line(XCur,MaxY-60-YCur,XCur,MaxY-60-YCur);
			   Horizon(Xi,Yi,XCur,YCur/*,HMax,HMin*/);
			}
			else
			{
			   Intersect(XPre,YPre,XCur,YCur,HMin[XPre],HMin[XCur],&Xi,&Yi);
			   if(0<=Xi)
			      line(XPre,MaxY-60-YPre,Xi,MaxY-60-Yi);
			   else if(0<=Yi)
			      line(XPre,MaxY-60-YPre,XPre,MaxY-60-Yi);
			   else
			      line(XPre,MaxY-60-YPre,XPre,MaxY-60-YPre);
			   Horizon(XPre,YPre,Xi,Yi/*,HMax,HMin*/);
			   Intersect(XPre,YPre,XCur,YCur,HMax[XPre],HMax[XCur],&Xi,&Yi);
			   if(0<=Xi)
			      line(Xi,MaxY-60-Yi,XCur,MaxY-60-YCur);
			   else if(0<=Yi)
			      line(XCur,MaxY-60-Yi,XCur,MaxY-60-YCur);
			   else
			      line(XCur,MaxY-60-YCur,XCur,MaxY-60-YCur);
			   Horizon(Xi,Yi,XCur,YCur/*,HMax,HMin*/);
			}
		   }
		   else
		   {
		       if(VisPre==0)
			{
			   Intersect(XPre,YPre,XCur,YCur,HMin[XPre],HMin[XCur],&Xi,&Yi);
			   if(0<=Xi)
			      line(Xi,MaxY-60-Yi,XCur,MaxY-60-YCur);
			   else if(0<=Yi)
			      line(XCur,MaxY-60-Yi,XCur,MaxY-60-YCur);
			   else
			      line(XCur,MaxY-60-YCur,XCur,MaxY-60-YCur);
			   Horizon(Xi,Yi,XCur,YCur/*,HMax,HMin*/);
			}
			else
			{
			   Intersect(XPre,YPre,XCur,YCur,HMax[XPre],HMax[XCur],&Xi,&Yi);
			   if(0<=Xi)
			      line(XPre,MaxY-60-YPre,Xi,MaxY-60-Yi);
			   else if(0<=Yi)
			      line(XPre,MaxY-60-YPre,XPre,MaxY-60-Yi);
			   else
			      line(XPre,MaxY-60-YPre,XPre,MaxY-60-YPre);
			   Horizon(XPre,YPre,Xi,Yi/*,HMax,HMin*/);
			   Intersect(XPre,YPre,XCur,YCur,HMin[XPre],HMin[XCur],&Xi,&Yi);
			   if(0<=Xi)
			      line(Xi,MaxY-60-Yi,XCur,MaxY-60-YCur);
			   else if(0<=Yi)
			      line(XCur,MaxY-60-Yi,XCur,MaxY-60-YCur);
			   else
			      line(XCur,MaxY-60-YCur,XCur,MaxY-60-YCur);
			   Horizon(Xi,Yi,XCur,YCur/*,HMax,HMin*/);
			}
		   }
	       }
	   }
	   VisPre=VisCur;XPre=XCur;YPre=YCur;
       }
       if(Xg!=-1)Horizon(Xg,Yg,XCur,YCur/*,HMax,HMin*/);
       Xg=XCur;Yg=YCur;
    }
}
void main()
{
   int gdriver=DETECT,gmode;
   initgraph(&gdriver,&gmode,"");
   ProbSurf(-190,-120,190,120,20.0,20.0,300.0,22.20765,20.704811,158,100);
   getch();
   closegraph();
}
