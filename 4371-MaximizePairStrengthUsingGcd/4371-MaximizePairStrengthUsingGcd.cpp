// Last updated: 19/8/2026, 11:57:39 pm
class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
        long long ans=0;
        int  n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                long long g=__gcd(nums[i],nums[j]);
                long long k=(1ll*nums[i]*nums[j])/(1ll*g*g);
                ans=max(ans,k);
            }
        }
        return ans;
    }
};