// Last updated: 10/27/2025, 7:09:29 PM
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        int ones=0,twos=0;
        for(int i=0;i<n;i++){
            ones=(ones^nums[i])&~twos;
            twos=(twos^nums[i])&~ones;
        }
        return ones;
    }
};