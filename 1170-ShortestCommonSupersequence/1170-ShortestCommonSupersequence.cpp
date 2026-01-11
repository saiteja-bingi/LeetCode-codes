// Last updated: 1/11/2026, 10:03:30 PM
class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else{
                    int left=dp[i-1][j];
                    int right=dp[i][j-1];
                    dp[i][j]=max(left,right);
                }
            }
        }
        int i=n,j=m;
        string ans="";
        while(j>0&&i>0){
            if(s1[i-1]==s2[j-1]){
                ans+=s1[i-1];
                i--;
                j--;
            }
            else if(dp[i-1][j]>dp[i][j-1]){
                ans+=s1[i-1];
                i--;
            }
            else{
                ans+=s2[j-1];
                j--;
            }
        }
        while(i>0) ans+=s1[--i];
        while(j>0) ans+=s2[--j];

        reverse(ans.begin(),ans.end());
        return ans;
    }
};