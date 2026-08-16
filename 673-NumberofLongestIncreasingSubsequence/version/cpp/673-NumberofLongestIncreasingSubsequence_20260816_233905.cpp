// Last updated: 16/8/2026, 11:39:05 pm
1class Solution {
2public:
3    int findNumberOfLIS(vector<int>& nums) {
4        // dp[i]=len of longest sub seq at i
5        int n=nums.size();
6        vector<int>dp(n+1,1),cnt(n+1,1);
7        for(int i=1;i<n;i++){
8            for(int j=0;j<i;j++){
9                if(nums[i]>nums[j]){
10                    if(dp[j]+1>dp[i]){
11                        dp[i]=dp[j]+1;
12                        cnt[i]=cnt[j];
13                    }
14                    else if(dp[j]+1==dp[i]){
15                        cnt[i]+=cnt[j];
16                    }
17                }
18            }
19        }
20        int mx=*max_element(dp.begin(),dp.end());
21        int ans=0;
22        for(int i=0;i<n;i++){
23            if(dp[i]==mx){
24                ans+=cnt[i];
25            }
26        }
27        return ans;
28
29    }
30};