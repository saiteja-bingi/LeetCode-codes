# Last updated: 10/8/2026, 10:45:36 pm
1class Solution:
2    def winnerSquareGame(self, n: int) -> bool:
3        dp=[False]*(n+1)
4        for i in range(1,n+1):
5            j=1
6            while j*j<=i:
7                if not dp[i-j*j]:
8                    dp[i]=True
9                    break
10                j+=1
11        return dp[n]
12