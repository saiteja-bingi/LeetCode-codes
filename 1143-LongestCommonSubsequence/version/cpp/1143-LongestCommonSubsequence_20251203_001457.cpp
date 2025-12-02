// Last updated: 12/3/2025, 12:14:57 AM
1class Solution {
2public:
3
4    int findsol(string &s1,string& s2,int i,int j,vector<vector<int>>&dp){
5        if(i==s1.size()||j==s2.size()) return 0;
6
7        if(dp[i][j]!=-1) return dp[i][j];
8        if(s1[i]==s2[j]){
9            dp[i][j]=1+findsol(s1,s2,i+1,j+1,dp);
10        }
11        else{
12            int ans=max(findsol(s1,s2,i,j+1,dp),findsol(s1,s2,i+1,j,dp));
13            dp[i][j]=ans;
14        }
15        return dp[i][j];
16    }
17    int longestCommonSubsequence(string text1, string text2) {
18        int n=text1.size();
19        int m=text2.size();
20        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
21        for(int i=1;i<=n;i++){
22            for(int j=1;j<=m;j++){
23                int ans=0;
24                if(text1[i-1]==text2[j-1]){
25                    ans=1+dp[i-1][j-1];
26                }
27                else{
28                    ans=max(dp[i][j-1],dp[i-1][j]);
29                }
30                dp[i][j]=ans;
31            }
32        }
33        return dp[n][m];
34
35    }
36};