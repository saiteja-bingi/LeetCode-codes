// Last updated: 10/27/2025, 7:05:03 PM
class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int k=INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=i){
                k&=nums[i];
            }
        }
        if(k==INT_MAX) return 0;
        else return k;
    }
};