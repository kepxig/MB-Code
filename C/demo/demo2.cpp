//Authors:xiaobei

#include<stdio.h>
#include<stdlib.h>
#define MaxInt 32767
#define MVNum 100
typedef char VerTexType;
typedef int ArcType;
//����ͼ�ṹ
typedef struct{
 VerTexType vexs[MVNum];
 ArcType arcs[MVNum][MVNum];
 int vexnum,arcnum;
}AMGraph;
//���帨������
typedef struct QNode{
 char data;
 struct QNode *next;
}QNode,*QueuePtr;
typedef struct{
 QueuePtr front;
 QueuePtr rear;
}LinkQueue;
//����ȫ�ָ�������visited[MVNum]
int visited[MVNum];
//�������ض����±�
int LocateVex(AMGraph G,char v){
 int i;
 for(i=0;i<G.vexnum;i++)
  if(G.vexs[i]==v)
   return i;
  return -1;
}
//�������ʲ�������㣬�����±�
int visit(AMGraph G,char v){
 int i;
 for(i=0;i<G.vexnum;i++)
  if(v==G.vexs[i])
   printf("%c",v);
 return LocateVex(G,v);
}
//������������ͼ�����ڽӾ�����ʽ
int CreateUDN(AMGraph &G){
 int i,j,k,v1,v2,w;
 printf("[�����ܶ������ͱ���:]\n>>>");
 scanf("%d %d",&G.vexnum,&G.arcnum);
 for(i=0;i<G.vexnum;i++)
 {
  getchar();
  printf("[����������������Ϣ:]\n>>>");
  scanf("%c",&G.vexs[i]);
 }
 for(i=0;i<G.vexnum;i++)
  for(j=0;j<G.vexnum;j++)
   G.arcs[i][j] = MaxInt;
 for(k=0;k<G.arcnum;k++){
  getchar();
  printf("[����һ���������Ķ��㼰Ȩֵ:]\n>>>"); 
  scanf("%c %c %d",&v1,&v2,&w);
  i = LocateVex(G,v1);
  j = LocateVex(G,v2);
  G.arcs[i][j]=w;
  G.arcs[j][i]=G.arcs[i][j];
 }
 return 1;
}
//������ȱ�����ͨͼ
void DFS_AM(AMGraph G,char v){
 int w,u;
 u = visit(G,v);
 visited[u] = 1;
 for(w=0;w<G.vexnum;w++){
  if((G.arcs[u][w]<MaxInt) && (!visited[w]))
   DFS_AM(G,G.vexs[w]);
 }
}
//������ʼ������
void InitQueue(LinkQueue &Q){
 Q.front = Q.rear = (QNode*)malloc(sizeof(QNode));
 Q.front->next=NULL;
}
//�������ݽ���
void EnQueue(LinkQueue &Q,char e){
 QueuePtr p;
 p = (QNode*)malloc(sizeof(QNode));
 p->data = e;
 p->next = NULL;
 Q.rear->next=p;
 Q.rear = p;
}
//�������ݳ���
void DeQueue(LinkQueue &Q,char &e){
 QueuePtr p;
 if(Q.front==Q.rear);
 else
 {
  p = Q.front->next;
  e = p->data;
  Q.front->next = p->next;
  if(Q.rear==p)
   Q.rear=Q.front;
  free(p);
 }
}
//�����ж������Ƿ�Ϊ��
int QueueEmpty(LinkQueue Q){
 if(Q.front==Q.rear)
  return 1;
 else
  return 0;
}
//�������ض�����һ���ڽӵ��±�
int FirstAdjVex(AMGraph G,int c){
 int j;
 for(j=0;j<G.vexnum;j++)
  if(G.arcs[c][j]<MaxInt && visited[j]==0)
   return j;
  return -1;
}
//�������ض�����һ������ڽӵ��±�
int NextAdjVex(AMGraph G,int c,int w){
 int j;
 for(j=0;j<G.vexnum;j++)
  if(G.arcs[c][j]<MaxInt && visited[j]==0)
   return j;
  return -1;
}
//������ȱ�����ͨͼ
void BFS_AM(AMGraph G,char v){
 int c,w,i;
 char u;
 LinkQueue Q;
 c = visit(G,v);
 visited[c] = 1;
 InitQueue(Q);
 EnQueue(Q,v);
 while(!QueueEmpty(Q)){
  DeQueue(Q,u);
  c = LocateVex(G,u);
  for(w=FirstAdjVex(G,c);w>=0;w=NextAdjVex(G,c,w))
  {
   if(!visited[w]){
    i = visit(G,G.vexs[w]);
    visited[i] = 1;
    EnQueue(Q,G.vexs[w]);
   }
  }
 }
}
//�˵���ӡ
void Menu(){
 printf("\n�����������������˵�����������������\n");
 printf("\n1.����ͼ�ṹ;\n");
 printf("\n2.��ȱ�����DFS��;\n");
 printf("\n3.��ȱ�����BFS��;\n");
 printf("\n0.�˳�;\n");
 printf("\n������������������������������������\n");
 printf("[���������ѡ��:]\n>>>");
}
//������
int main(){
 int i,user;
 char v;
 AMGraph G;
 while(1){
  Menu();
  scanf("%d",&user);
  switch(user){
  case 1:{
   CreateUDN(G);
   break;
  }
  case 2:{
   //��ʼ����������
   for(i=0;i<G.vexnum;i++)
    visited[i] = 0;
   printf("[�����������ʼ�Ķ���:]\n>>>");
   getchar();
   scanf("%c",&v);
   DFS_AM(G,v);
   break;
  }
  case 3:{
   //��ʼ����������
   for(i=0;i<G.vexnum;i++)
    visited[i] = 0;
   printf("[�����������ʼ�Ķ���:]\n>>>");
   getchar();
   scanf("%c",&v);
   BFS_AM(G,v);
   break;
  }
  case 0:{
   exit(0);
   break;
  }
  }
 }
 return 0;
}