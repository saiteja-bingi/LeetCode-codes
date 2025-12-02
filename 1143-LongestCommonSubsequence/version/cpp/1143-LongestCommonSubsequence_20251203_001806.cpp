// Last updated: 12/3/2025, 12:18:06 AM
1class Solution {
2public:
3
4    int longestCommonSubsequence(string text1, string text2) {
5        int n=text1.size();
6        int m=text2.size();
7        vector<int>dp(m+1,0);
8        for(int i=1;i<=n;i++){
9            vector<int>temp(m+1,0);
10            for(int j=1;j<=m;j++){
11                int ans=0;
12                if(text1[i-1]==text2[j-1]){
13                    ans=1+dp[j-1];
14                }
15                else{
16                    ans=max(temp[j-1],dp[j]);
17                }
18                temp[j]=ans;
19            }
20            dp=temp;
21        }
22        return dp[m];
23
24    }
25};