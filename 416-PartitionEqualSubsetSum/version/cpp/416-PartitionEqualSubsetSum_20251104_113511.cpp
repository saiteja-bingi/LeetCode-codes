// Last updated: 11/4/2025, 11:35:11 AM
class Solution {
public:
    bool solve(vector<int>&nums,int i,int target,vector<vector<int>>&dp){
        if(target==0) return true;
        if(target<0) return false;
        if(i==0){
            return false;
        }
        if(dp[i][target]!=-1) return dp[i][target];
        bool ans=false;
        ans|=solve(nums,i-1,target,dp);
        ans|=solve(nums,i-1,target-nums[i],dp);
        return dp[i][target] = ans;
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int target=accumulate(nums.begin(),nums.end(),0);
        if(target%2!=0) return false;
        vector<vector<bool>>dp(n,vector<bool>(target,false));
        target/=2;
        // bool ans=solve(nums,n-1,target,dp);

        // tabilation
        for(int i=0;i<n;i++){
            dp[i][0]=true;
        }
        if(nums[0]<=target) dp[0][nums[0]]=true;
        for(int i=1;i<n;i++){
            for(int sum=0;sum<=target;sum++){
                bool ans=false;
                ans|=dp[i-1][sum];
                if(sum-nums[i]>=0) ans|=dp[i-1][sum-nums[i]];
                dp[i][sum]=ans;
            }
        }
        return dp[n-1][target];
    }
};