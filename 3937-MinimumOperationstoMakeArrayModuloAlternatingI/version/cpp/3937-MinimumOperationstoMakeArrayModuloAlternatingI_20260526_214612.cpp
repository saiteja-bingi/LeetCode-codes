// Last updated: 26/5/2026, 9:46:12 pm
1class Solution {
2public:
3    int minOperations(vector<int>& nums, int k) {
4        for(auto &it:nums) it%=k;
5        int n=nums.size();
6        int ans=INT_MAX;
7        for(int k1=0;k1<k;k1++){
8            for(int k2=0;k2<k;k2++){
9                if(k1==k2) continue;
10                int c1=0;
11                for(int i=0;i<n;i++){
12                    int d=0;
13                    if(i%2==0) d=abs(k1-nums[i]);
14                    else d=abs(k2-nums[i]);
15                    c1+=min(d,k-d);
16                }
17                ans=min(ans,c1);
18            }
19        }
20        return ans;
21    }
22};