// Last updated: 15/04/2026, 00:42:25
class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int c=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            string s=to_string(nums[i]);
            for(auto it:s) if(it==digit+'0') c++;
        }
        return c;
    }
};