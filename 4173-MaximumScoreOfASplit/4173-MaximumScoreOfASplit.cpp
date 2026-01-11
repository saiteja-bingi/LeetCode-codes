// Last updated: 1/11/2026, 11:09:53 AM
class Solution {
public:
    long long maximumScore(vector<int>& nums) {
        long long n=nums.size();
        vector<long long>pre(n),suf(n);
        pre[0]=nums[0];
        for(long long i=1;i<n;i++){
            pre[i]=nums[i]+pre[i-1];
        }
        suf[n-1]=INT_MAX;
        suf[n-2]=nums[n-1];
        for(long long i=n-3;i>=0;i--){
            suf[i]=min(1ll*nums[i+1],suf[i+1]);
        }
        for(int i=0;i<n;i++){
            cout<<suf[i]<<" ";
        }
        long long ans=LLONG_MIN;
        for(long long i=0;i<n-1;i++){
            ans=max(ans,(pre[i]-suf[i]));
        }
        return ans;
    }
};