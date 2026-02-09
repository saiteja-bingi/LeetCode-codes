// Last updated: 09/02/2026, 21:07:11
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int target=accumulate(nums.begin(),nums.end(),0);
        if(target%2!=0) return false;
        vector<bool>dp(target+1,false);
        target/=2;

        // tabilation
        if(nums[0]<=target) dp[0]=true;
        for(int i=1;i<n;i++){
            vector<bool>temp(target+1,false);
            temp[0]=true;
            for(int sum=0;sum<=target;sum++){
                bool ans=false;
                ans|=dp[sum];
                if(sum-nums[i]>=0) ans|=dp[sum-nums[i]];
                temp[sum]=ans;
            }
            dp=temp;
        }
        return dp[target];
    }
};