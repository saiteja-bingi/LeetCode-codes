// Last updated: 3/8/2026, 6:40:17 pm
1class Solution {
2public:
3    string stoneGameIII(vector<int>& s) {
4        int n=s.size();
5        int dp[n+1];
6        fill(dp,dp+n+1,INT_MIN);
7        dp[n]=0;
8        for(int i=n-1;i>=0;i--){
9            int sum=0;
10            for(int j=1;j<=3&&i+j<=n;j++){
11                sum+=s[i+j-1];
12                dp[i]=max(dp[i],sum-dp[i+j]);
13            }
14        }
15        if(dp[0]==0) return "Tie";
16        if(dp[0]>0) return "Alice";
17        return "Bob";
18    }
19};