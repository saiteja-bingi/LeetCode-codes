// Last updated: 10/27/2025, 7:05:08 PM
class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        int count=nums.size();
        for(int i=1;i<nums.size();i++){
            if(nums[i]<nums[i-1]){
                nums[i]=nums[i-1];
                count--;
            }
        }
        return count;
    }
};