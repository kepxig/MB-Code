n=int(input())
coins=list(map(n,input().split()))
dp=[0]*(n+1)
dp[1]=coins[0]
for i in range(2,n+1):
    dp[i]=max(dp[i-1]+coins[i-1],dp[i-1])
print(dp[n])