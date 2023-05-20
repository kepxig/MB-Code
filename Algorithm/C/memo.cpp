//半数集问题，求1...n的半数集个数
#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

int memo[100000]; //声明一个记忆化数组，用于避免重复计算

int comb(int n){
    if(memo[n]!=0) //如果n已经计算过，直接返回记忆化数组中的值
        return memo[n];
    int ans = 1;
    if( n > 1 )
        for( int i = 1; i <= n/2; i++ )
            ans += comb(i);
    memo[n]=ans; //将计算结果保存到记忆化数组中
    return ans;
}

int main(){
    int n;
    while( scanf("%d",&n) != EOF ){
        cout<<comb(n)<<endl;
    }
    return 0;
} 

//本代码通过添加记忆化数组，避免了重复计算，同时优化了代码