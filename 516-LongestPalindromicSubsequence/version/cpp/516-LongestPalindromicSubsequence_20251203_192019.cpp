// Last updated: 12/3/2025, 7:20:19 PM
1class Solution {
2public:
3
4    int findsol(string& s,int i,int j,vector<vector<int>>&dp){
5        if(j<i||i>=s.size()||j<0) return 0;
6        if(dp[i][j]!=-1) return dp[i][j];
7        int ans=0;
8        if(s[i]==s[j]){
9            ans=((i!=j)?2:1)+findsol(s,i+1,j-1,dp);
10        }
11        else{
12            int a1=findsol(s,i+1,j,dp);
13            int a2=findsol(s,i,j-1,dp);
14            ans=max(a1,a2);
15        }
16        return dp[i][j]= ans;
17
18    }
19    int longestPalindromeSubseq(string s) {
20        int n=s.size();
21        vector<vector<int>>dp(n,vector<int>(n,-1));
22        return findsol(s,0,n-1,dp);
23    }
24};