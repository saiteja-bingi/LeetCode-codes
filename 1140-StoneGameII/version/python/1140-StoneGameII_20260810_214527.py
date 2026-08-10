# Last updated: 10/8/2026, 9:45:27 pm
1class Solution:
2    def stoneGameII(self, piles: List[int]) -> int:
3        n=len(piles)
4        suffix=[0]*(n+1)
5        for i in range(n-1,-1,-1):
6            suffix[i]+=suffix[i+1]+piles[i]
7        dp=[[0]*(n+1) for _ in range(n+1)]
8        
9        for i in range(n,-1,-1):
10            for m in range(1,n+1):
11                if i+2*m>=n:
12                    dp[i][m]=suffix[i]
13                else:
14                    best=0
15                    for x in range(1,2*m+1):
16                        newm=max(m,x)
17                        best=max(best,suffix[i]-dp[i+x][newm])
18                    dp[i][m]=best
19        return dp[0][1]
20