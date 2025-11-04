// Last updated: 11/4/2025, 11:05:43 AM
class Solution {
public:
    bool solve(vector<int>&arr,int i,int target,vector<vector<int>>&dp){
        if(target==0) return true;
        if(target<0) return false;
        if(i==0){
            return false;
        }
        if(dp[i][target]!=-1) return dp[i][target];
        bool ans=false;
        ans|=solve(arr,i-1,target,dp);
        ans|=solve(arr,i-1,target-arr[i],dp);
        return dp[i][target] = ans;
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%2!=0) return false;
        vector<vector<int>>dp(n,vector<int>(sum,-1));
        sum/=2;
        bool ans=solve(nums,n-1,sum,dp);
        return ans;
    }
};