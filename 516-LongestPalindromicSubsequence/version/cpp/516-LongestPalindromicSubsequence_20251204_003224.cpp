// Last updated: 12/4/2025, 12:32:24 AM
1class Solution {
2public:
3    int longestPalindromeSubseq(string s) {
4        int n=s.size();
5        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
6        string s2=s;
7        reverse(s2.begin(),s2.end());
8
9        for(int i=1;i<=n;i++){
10            for(int j=1;j<=n;j++){
11                int ans=0;
12                if(s[i-1]==s2[j-1]){
13                    ans=1+dp[i-1][j-1];
14                }
15                else{
16                    int a1=dp[i-1][j];
17                    int a2=dp[i][j-1];
18                    ans=max(a1,a2);
19                }
20                dp[i][j]=ans;
21            }
22        }
23        // if(n%2!=0) dp[n][n]++;
24        return dp[n][n];
25
26    }
27};