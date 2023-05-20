//快速排序：对冒泡排序的改进
//思想：通过一趟排序将要排序的数据分割成独立的两部分，其中一部分的所有数据都比另外一部分的所有数据都要小，然后再按此方法对这两部分数据分别进行快速排序，整个排序过程可以递归进行，以此达到整个数据变成有序序列
 
#include<iostream>
#include<time.h>
 
using namespace std;
 
void randData(int* a,int n)    //产生n个0-99的随机数，用于创建随机数组用来作为排序前数列
{
	srand(time(NULL));
	for(int i=0;i<n;i++)
	{
		a[i] = rand()%99;
		cout<<a[i]<<",";
	}
	cout<<endl;
}
 
void Qsort(int* a,int start,int end)   //快速排序主体代码函数
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
 
void show(int* a,int n)        //输出函数
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