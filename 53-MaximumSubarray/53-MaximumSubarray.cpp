// Last updated: 10/27/2025, 7:10:20 PM
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ms=INT_MIN,cs;
        for(int i=0;i<nums.size();i++){
            cs+=nums[i];
            ms=max(ms,cs);
            if(cs<0) cs=0;
        }
        return ms;
    }
};