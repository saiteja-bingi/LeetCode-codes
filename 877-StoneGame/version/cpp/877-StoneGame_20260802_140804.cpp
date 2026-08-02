// Last updated: 2/8/2026, 2:08:04 pm
1class Solution {
2public:
3    bool stoneGame(vector<int>& piles) {
4        int n=piles.size();
5        int dp[500][500];
6        memset(dp,0,sizeof(dp));
7        for(int i=0;i<n;i++) dp[i][i]=piles[i];
8        for(int l=2;l<=n;l++){
9            for(int i=0;i+l-1<n;i++){
10                int j=i+l-1;
11                dp[i][j]=max(piles[i]-dp[i+1][j],piles[j]-dp[i][j-1]);
12            }
13        }
14        return dp[0][n-1]>=0;
15    }
16};