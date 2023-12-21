#include"graphics.h"
#define WINDOW_HEIGHT 480
#define NULL 0
typedef struct tEdge
{
   int ymax;
   float x, dx;
   struct tEdge *next;
}Edge;
typedef struct point{ int x,y;}POINT;
/*Inserts edge into list in order of increasing xIntersect field.*/
void InsertEdge(Edge * list,Edge * edge)
{
  Edge * p,*q=list;
  p=q->next;
  while(p!=NULL)
  { if(edge->x<p->x)
       p=NULL;
    else
    { q=p;
      p=p->next;
    }
  }
  edge->next=q->next;
  q->next=edge;
}

/*For an index,return y-coordinate of next nonhorizontal line */
int yNext(int k,int cnt,POINT * pts)
{
  int j;
  if((k+1)>(cnt-1))
     j=0;
  else
     j=k+1;
  while(pts[k].y==pts[j].y)
     if((j+1)>(cnt-1))
	j=0;
     else
	j++;
  return(pts[j].y);
}
/*Store lower-x coordinate and inverse slope for each edge. Adjust
  and store Upper-y coordinate for edges that are the lower member
  of a monotonically increasing or decreasing pair of edges */
void MakeEdgeRec(POINT lower,POINT upper,int yComp,Edge * edge,Edge * edges[])
{  edge->dx=(float)(upper.x-lower.x)/(upper.y-lower.y);
   edge->x=lower.x;
   if(upper.y<yComp)
      edge->ymax=upper.y-1;
   else
      edge->ymax=upper.y;
   InsertEdge(edges[lower.y],edge);
}
void BuildEdgeList(int cnt,POINT * pts, Edge * edges[])
{
   Edge *edge;
   POINT v1,v2;
   int i,yPrev=pts[cnt-2].y;
   v1.x=pts[cnt-1].x;
   v1.y=pts[cnt-1].y;
   for(i=0;i<cnt;i++)
   {  v2=pts[i];
      if(v1.y!=v2.y)    /* nonhorizontal line */
      {
	 edge=(Edge *)malloc(sizeof(Edge));
	 if(v1.y<v2.y)     /*down-going edge */
	     MakeEdgeRec(v1,v2,yNext(i,cnt,pts),edge,edges);
	 else              /*down-going edge */
	     MakeEdgeRec(v2,v1,yPrev,edge,edges);
      }
      yPrev=v1.y;
      v1=v2;
   }
}
void BuildActiveList(int scan,Edge * active,Edge * edges[])
{
  Edge *p,*q;
  p=edges[scan]->next;
  while(p)
    { q=p->next;
      InsertEdge(active,p);
      p=q;
    }
}

void FillScan(int scan,Edge * active,int color)
{
   Edge *p1, *p2;
   int i;
   p1=active->next;
   while(p1)
   {
      p2=p1->next;
      for(i=p1->x;i<p2->x;i++)
	 putpixel((int)i,scan,color);
      p1=p2->next;
    }
}
void DeleteAfter(Edge *q)
{
   Edge *p=q->next;
   q->next=p->next;
   free(p);
}
/*Delete completed edges. Update 'xIntersect' field for others */
void UpdateActiveList(int scan,Edge * active)
{
   Edge *q=active,*p=active->next;
   while(p)
   if(scan>=p->ymax)
     { p=p->next;
       DeleteAfter(q);
     }
   else
     { p->x=p->x+p->dx;
       q=p;p=p->next;
     }
}

void ResortActiveList(Edge * active)
{
   Edge *q,*p=active->next;
   active->next=NULL;
   while(p)
    { q=p->next;
      InsertEdge(active,p);
      p=q;
    }
}
void ScanFill(int cnt,POINT *pts,int color)
{
   Edge * edges[WINDOW_HEIGHT],*active;
   int i, scan, scanmax = 0, scanmin = WINDOW_HEIGHT;
   for (i = 0; i < cnt-1; i++)
     { if (scanmax < pts [i].y ) scanmax = pts [i].y;
       if (scanmin > pts [i].y ) scanmin = pts [i].y;
     }
   for(scan=scanmin;scan<=scanmax;scan++)
     {  edges[scan]=(Edge *)malloc(sizeof(Edge));
	edges[scan]->next=NULL;
     }
   BuildEdgeList(cnt,pts,edges);
   active=(Edge *)malloc(sizeof(Edge));
   active->next=NULL;
   for(scan=scanmin;scan<=scanmax;scan++)
     {
	BuildActiveList(scan,active,edges);
	if(active->next)
	  {  FillScan(scan,active,color);
	     UpdateActiveList(scan,active);
	     ResortActiveList(active);
	  }
     }
     /*Free edge records that have been malloc'ed...*/
}
void main()
{
   POINT pts[7];
   int gdriver=DETECT,gmode;

   pts[0].x=100;pts[0].y=40;
   pts[1].x=220;pts[1].y=140;
   pts[2].x=280;pts[2].y=80;
   pts[3].x=350;pts[3].y=300;
   pts[4].x=200;pts[4].y=380;
   pts[5].x=50;pts[5].y=280;
   pts[6].x=100;pts[6].y=40;

   initgraph(&gdriver,&gmode,"");
   ScanFill(7,pts,2);
   getch();
}







