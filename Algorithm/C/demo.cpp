//�������򣺶�ð������ĸĽ�
//˼�룺ͨ��һ������Ҫ��������ݷָ�ɶ����������֣�����һ���ֵ��������ݶ�������һ���ֵ��������ݶ�ҪС��Ȼ���ٰ��˷����������������ݷֱ���п�����������������̿��Եݹ���У��Դ˴ﵽ�������ݱ����������
 
#include<iostream>
#include<time.h>
 
using namespace std;
 
void randData(int* a,int n)    //����n��0-99������������ڴ����������������Ϊ����ǰ����
{
	srand(time(NULL));
	for(int i=0;i<n;i++)
	{
		a[i] = rand()%99;
		cout<<a[i]<<",";
	}
	cout<<endl;
}
 
void Qsort(int* a,int start,int end)   //��������������뺯��
{
	if(start>=end) return;
	int i = start;
	int j = end;
	int key = a[i];
	while (i<j)
	{
		while(i<j&&a[j]>=key)
		{
			j--;
		}
		a[i] = a[j];
		while(i<j&&a[i]<=key)
		{
			i++;
		}
		a[j] = a[i];
	}
	a[i] = key;
	Qsort(a,start,i-1);
	Qsort(a,i+1,end);
}
 
void show(int* a,int n)        //�������
{
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<",";
	}
	cout<<endl;
}
 
int main()
{
	const int n = 10;
	int a[n];
	randData(a,n);
	Qsort(a,0,n-1);
	show(a,n);
	return 0;
}