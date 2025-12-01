// Last updated: 12/1/2025, 7:13:07 PM
class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        if(k == 0) return nums.size();
        sort(nums.begin(), nums.end());
        int i = nums.size() - k, n = nums[i];
        if(nums[0] == n) return 0;
        while(n == nums[i]) i--;
        return i + 1;
    }
};