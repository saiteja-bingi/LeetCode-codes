// Last updated: 09/02/2026, 21:07:04
class Solution {
public:

    int findsol(string& s,int i,int j,vector<vector<int>>&dp){
        if(i>=s.size()||j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=0;
        if(s[i]==s[j]){
            ans=((i!=j)?1:1)+findsol(s,i+1,j-1,dp);
        }
        else{
            int a1=findsol(s,i+1,j,dp);
            int a2=findsol(s,i,j-1,dp);
            ans=max(a1,a2);
        }
        return dp[i][j]= ans;

    }
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return findsol(s,0,n-1,dp);
    }
};