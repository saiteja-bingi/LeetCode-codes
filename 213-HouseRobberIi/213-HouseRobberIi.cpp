// Last updated: 10/27/2025, 7:08:25 PM
class Solution {
public:
    vector<int>dp;
    int findsol1(vector<int>&nums,int i){
        if(i<0) return 0;
        if(dp[i]!=-1) return dp[i];
        int take=nums[i]+findsol1(nums,i-2);
        int untake=findsol1(nums,i-1);
        dp[i]=max(take,untake);
        return dp[i];
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int>nums2(nums.begin()+1,nums.end());
        dp.assign(n-1,-1);
        int ans1= findsol1(nums2,n-2);
        
        dp.assign(n,-1);
        int ans2=findsol1(nums,n-2);
        return max(ans1,ans2);
    }
};