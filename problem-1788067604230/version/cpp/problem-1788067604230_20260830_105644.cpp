// Last updated: 30/8/2026, 10:56:44 am
1class Solution {
2public:
3    int minimumDeletions(vector<int>& nums) {
4        int n=nums.size();
5        int mi=min_element(nums.begin(),nums.end())-nums.begin();
6        int ma=max_element(nums.begin(),nums.end())-nums.begin();
7        if(ma<mi) swap(mi,ma);
8        int ans=INT_MAX;
9        ans=min({ma+1,n-mi,mi+1+n-ma});
10        return ans;
11    }
12};