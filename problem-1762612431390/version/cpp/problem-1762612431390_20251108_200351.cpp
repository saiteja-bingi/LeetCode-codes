// Last updated: 11/8/2025, 8:03:51 PM
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size();
        int ele=*max_element(nums.begin(),nums.end());
        int count=0;
        for(int i=0;i<n;i++){
            count+=abs(nums[i]-ele);
        }
        return count;
    }
};