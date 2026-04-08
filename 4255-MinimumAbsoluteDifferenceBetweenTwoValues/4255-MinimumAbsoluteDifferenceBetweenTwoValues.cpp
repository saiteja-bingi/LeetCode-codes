// Last updated: 08/04/2026, 23:54:36
class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        int pi=0,pn=0;
        int mi=INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) continue;
            if(pn==3-nums[i]&&i-pi<mi){
                mi=i-pi;
            }
            pi=i;
            pn=nums[i];
        }
        if(mi==INT_MAX) return -1;
        return mi;
    }
};