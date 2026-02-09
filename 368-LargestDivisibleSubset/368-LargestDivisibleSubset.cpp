// Last updated: 09/02/2026, 21:07:14
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int>dp(n,0),hash(n);
        for(int i=0;i<n;i++) hash[i]=i;
        for(int i=0;i<n;i++){
            for(int pi=0;pi<i;pi++){
                if(nums[i]%nums[pi]==0&&dp[pi]+1>dp[i]){
                    dp[i]=dp[pi]+1;
                    hash[i]=pi;
                }
            }
        }
        int idx=max_element(dp.begin(),dp.end())-dp.begin();
        vector<int>ans;
        while(hash[idx]!=idx){
            ans.push_back(nums[idx]);
            idx=hash[idx];
        }
        ans.push_back(nums[idx]);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};