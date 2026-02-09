// Last updated: 09/02/2026, 21:07:19
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>lenarr;
        for(int i=0;i<n;i++){
            int idx=lower_bound(lenarr.begin(),lenarr.end(),nums[i])-lenarr.begin();
            if(idx<lenarr.size()) lenarr[idx]=nums[i];
            else lenarr.push_back(nums[i]);
        }
        return lenarr.size();
    }
};