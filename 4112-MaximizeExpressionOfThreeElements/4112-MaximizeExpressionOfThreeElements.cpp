// Last updated: 12/1/2025, 7:13:11 PM
class Solution {
public:
    int maximizeExpressionOfThree(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        long long ans=nums[n-1]+nums[n-2]-nums[0];
        return ans;
    }
};