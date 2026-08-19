// Last updated: 19/8/2026, 11:58:44 pm
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        for(auto &it:nums) it%=k;
        int n=nums.size();
        int ans=INT_MAX;
        for(int k1=0;k1<k;k1++){
            for(int k2=0;k2<k;k2++){
                if(k1==k2) continue;
                int c1=0;
                for(int i=0;i<n;i++){
                    int d=0;
                    if(i%2==0) d=abs(k1-nums[i]);
                    else d=abs(k2-nums[i]);
                    c1+=min(d,k-d);
                }
                ans=min(ans,c1);
            }
        }
        return ans;
    }
};