// Last updated: 18/5/2026, 10:27:38 pm
1class Solution {
2public:
3    vector<int> concatWithReverse(vector<int>& nums) {
4        int n=nums.size();
5        vector<int>ans(2*n);
6        for(int i=0;i<n;i++){
7            ans[i]=ans[2*n-i-1]=nums[i];
8        }
9        return ans;
10    }
11};