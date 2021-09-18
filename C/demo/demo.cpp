#include <iostream>
using namespace std;
int POSorNEG(int Arr[], int N);
int MaxSubsetSum(int arr[], int N);
int main()
{
   int n;
   cin >> n;
   int a[n];
   for (int i = 0; i < n; i++)
      cin >> a[i];
   if (POSorNEG(a, n))
   {
      int MaxSum = MaxSubsetSum(a, n);
      cout << MaxSum << endl;
   }
   else
      cout << 0 << endl;
}
int MaxSubsetSum(int Arr[], int N)
{
   int ThisSum, MaxSum = 0;

   for (int i = 0; i < N; i++)
   {
      ThisSum = 0;
      for (int j = i; j < N; j++)
      {
         ThisSum += Arr[j];
         if (MaxSum < ThisSum)
            MaxSum = ThisSum;
      }
   }
   return MaxSum;
}
int POSorNEG(int Arr[], int N)
{
   int Temp = 0;
   for (int i = 0; i < N; i++)
   {
      if (Arr[i] > 0)
      {
         Temp = 1;
         break;
      }
   }
   return Temp;
}