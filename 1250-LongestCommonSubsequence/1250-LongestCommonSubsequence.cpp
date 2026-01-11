// Last updated: 1/11/2026, 10:03:31 PM
class Solution {
public:

    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<int>dp(m+1,0);
        for(int i=1;i<=n;i++){
            vector<int>temp(m+1,0);
            for(int j=1;j<=m;j++){
                int ans=0;
                if(text1[i-1]==text2[j-1]){
                    ans=1+dp[j-1];
                }
                else{
                    ans=max(temp[j-1],dp[j]);
                }
                temp[j]=ans;
            }
            dp=temp;
        }
        return dp[m];

    }
};