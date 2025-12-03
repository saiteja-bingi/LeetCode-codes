// Last updated: 12/4/2025, 12:33:53 AM
1class Solution {
2public:
3    int longestPalindromeSubseq(string s) {
4        int n=s.size();
5        vector<int>dp(n+1,0);
6        string s2=s;
7        reverse(s2.begin(),s2.end());
8
9
10        for(int i=1;i<=n;i++){
11            vector<int>temp(n+1,0);
12            for(int j=1;j<=n;j++){
13                int ans=0;
14                if(s[i-1]==s2[j-1]){
15                    ans=1+dp[j-1];
16                }
17                else{
18                    int a1=dp[j];
19                    int a2=temp[j-1];
20                    ans=max(a1,a2);
21                }
22                temp[j]=ans;
23            }
24            dp=temp;
25        }
26        // if(n%2!=0) dp[n][n]++;
27        return dp[n];
28
29    }
30};