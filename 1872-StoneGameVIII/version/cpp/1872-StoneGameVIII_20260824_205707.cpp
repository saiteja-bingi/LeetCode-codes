// Last updated: 24/8/2026, 8:57:07 pm
1class Solution {
2public:
3    int stoneGameVIII(vector<int>& stones) {
4        int n=stones.size();
5        vector<long long>pre(n+1,0);
6        for(int i=0;i<n;i++){
7            pre[i+1]=pre[i]+stones[i];
8        }
9        vector<long long>dp(n+1,0);
10        dp[n]=pre[n];
11        for(int i=n-1;i>0;i--){
12            long long take=pre[i]-dp[i+1];
13            dp[i]=max(take,dp[i+1]);
14        }
15        return dp[2];
16    }
17};
18
19/*
20    -1 2 
21*/