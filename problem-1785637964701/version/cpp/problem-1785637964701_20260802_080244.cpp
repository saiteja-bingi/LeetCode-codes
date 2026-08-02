// Last updated: 2/8/2026, 8:02:44 am
1class Solution {
2public:
3    long long maxPairStrength(vector<int>& nums) {
4        long long ans=0;
5        int  n=nums.size();
6        for(int i=0;i<n;i++){
7            for(int j=i+1;j<n;j++){
8                long long g=__gcd(nums[i],nums[j]);
9                long long k=(1ll*nums[i]*nums[j])/(1ll*g*g);
10                ans=max(ans,k);
11            }
12        }
13        return ans;
14    }
15};