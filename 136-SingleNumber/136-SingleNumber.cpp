// Last updated: 10/27/2025, 7:09:14 PM
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int count=0;
        for(auto it:nums){
            count=count^it;
        }
        return count;
    }
};