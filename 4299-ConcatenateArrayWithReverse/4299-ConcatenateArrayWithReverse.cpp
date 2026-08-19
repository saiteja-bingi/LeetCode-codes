// Last updated: 19/8/2026, 11:58:47 pm
class Solution {
public:
    vector<int> concatWithReverse(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(2*n);
        for(int i=0;i<n;i++){
            ans[i]=ans[2*n-i-1]=nums[i];
        }
        return ans;
    }
};