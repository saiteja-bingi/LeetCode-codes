// Last updated: 17/8/2026, 11:42:17 am
1class Solution {
2public:
3    int stoneGameV(vector<int>& sv) {
4        int n=sv.size();
5        vector<int>ps(n+1,0);
6        for(int i=1;i<=n;i++) ps[i]=ps[i-1]+sv[i-1];
7        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
8        for(int l=2;l<=n;l++){
9            for(int i=1;i+l-1<=n;i++){
10                int j=i+l-1;
11                for(int cut=i;cut<j;cut++){
12                    int ll=cut-i+1;
13                    int rl=j-cut;
14                    int ls=ps[cut]-ps[i-1];
15                    int rs=ps[j]-ps[cut];
16                    if(ls>rs){
17                        dp[l][i]=max(dp[l][i],rs+dp[rl][cut+1]);
18                    }
19                    else if(rs>ls){
20                        dp[l][i]=max(dp[l][i],ls+dp[ll][i]);
21                    }
22                    else dp[l][i]=max({dp[l][i],ls+dp[ll][i],rs+dp[rl][cut+1]});
23                }
24            }
25        }
26        return dp[n][1];
27    }
28};