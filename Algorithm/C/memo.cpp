//���������⣬��1...n�İ���������
#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

int memo[100000]; //����һ�����仯���飬���ڱ����ظ�����

int comb(int n){
    if(memo[n]!=0) //���n�Ѿ��������ֱ�ӷ��ؼ��仯�����е�ֵ
        return memo[n];
    int ans = 1;
    if( n > 1 )
        for( int i = 1; i <= n/2; i++ )
            ans += comb(i);
    memo[n]=ans; //�����������浽���仯������
    return ans;
}

int main(){
    int n;
    while( scanf("%d",&n) != EOF ){
        cout<<comb(n)<<endl;
    }
    return 0;
} 

//������ͨ����Ӽ��仯���飬�������ظ����㣬ͬʱ�Ż��˴���