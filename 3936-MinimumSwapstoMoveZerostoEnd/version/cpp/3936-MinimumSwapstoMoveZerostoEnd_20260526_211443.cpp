// Last updated: 26/5/2026, 9:14:43 pm
1class Solution {
2public:
3    int minimumSwaps(vector<int>& nums) {
4        int n=nums.size();
5        int ans=0,c=0;
6        for(int i=0;i<n;i++) c+=(nums[i]==0);
7        for(int i=0;i<n-c;i++){
8            if(nums[i]==0) ans++;
9        }
10        return ans;
11    }
12};