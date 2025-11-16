// Last updated: 11/16/2025, 9:47:34 AM
class Solution {
public:
    int maximizeExpressionOfThree(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        long long ans=nums[n-1]+nums[n-2]-nums[0];
        return ans;
    }
};