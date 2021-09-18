#include <stdio.h>
#include <stdlib.h>
struct student //ѧ���ṹ��
{
  int num;      //ѧ��
  char name[9]; //����
  char sex[2];
  int age;
  float score; //�ɼ�
  float score2;
  float score3;
};
int main() //������
{
  //����ṹ������Ҹ�ֵ
  struct student stu[4] = {{1, "zhangsan", "M", 20, 86.3, 88.50, 78.50},
                           {2, "lisi", "F", 18, 78.5, 76.30, 68.50},
                           {3, "wangwu", "M", 19, 90.2, 85.60, 84.60},
                           {4, "zhaoliu", "F", 21, 76.5, 90.50, 85.50}};
  /*�������ƽ���ɼ�
  float sum1 = 0, sum2 = 0, sum3 = 0;
  
    for (int j = 0; j < 4; j++)
    {
      sum1 += stu[j].score;
    }
    for (int k = 0; k < 4; k++)
    {
      sum2 += stu[k].score2;
    }
    for (int l = 0; l < 4; l++)
    {
      sum3 += stu[l].score3;
    }
    float a1=sum1/4.0,a2=sum2/4.0,a3=sum3/4.0;
  printf("Chinese:%6.2f\nMath:%6.2f\nEnglish:%6.2f",a1,a2,a3);/*struct student t;
  */
  //�������ĳɼ��ɴ�С���ѧ����Ϣ//
  struct student t;
  int i, j, k;            //�������ͱ���
for (i = 0; i < 3; i++) //���forѭ��
  {
    k = i;                      //��i��ֵ����k
    for (j = i + 1; j < 4; j++) //�ڲ�forѭ��
    {
      if (stu[j].score > stu[k].score) //���������ߵ�
      {
        k = j; //����Ӧ��j��ֵ��k
      }
    }
    t = stu[k]; //�ѳɼ��ߵķŵ�ǰ��
    stu[k] = stu[i];
    stu[i] = t;
  }
  for (i = 0; i < 4; i++) //ѭ�����5���˵ĳɼ�
  {
    printf("%2d%10s%2s%4d%6.2f%6.2f%6.2f\n",
           stu[i].num,
           stu[i].name,
           stu[i].sex,
           stu[i].age,
           stu[i].score,
           stu[i].score2,
           stu[i].score3); //������
  }
  
      system("pause");
  return 0; //����������ֵΪ0
}