// Last updated: 12/2/2025, 11:16:32 PM
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
20        vector<vector<int>>dp(n,vector<int>(m,-1));
21        return findsol(text1,text2,0,0,dp);
22    }
23};