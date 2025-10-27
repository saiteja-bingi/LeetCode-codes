// Last updated: 10/27/2025, 7:09:52 PM
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return true;
        int maxindex=0;
        if(nums[0]==0) return false;
        for(int i=0;i<n;i++){
            maxindex=max(maxindex,i+nums[i]);
            if(maxindex==i&&nums[i]==0) return false;
            if(maxindex>=n-1) return true;
        }
        if(maxindex>=n-1) return true;
        return false;
    }
};