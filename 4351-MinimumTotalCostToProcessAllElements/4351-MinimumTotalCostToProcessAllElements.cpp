// Last updated: 19/8/2026, 11:58:07 pm
#define ll long long
int mod=1e9+7;
class Solution {
public:
    int minimumCost(vector<int>& nums, int k) {
        ll n=nums.size();
        ll a=k;
        ll c=0;
        __int128 ans=0;
        for(ll i=0;i<n;i++){
            if(a-nums[i]>=0){
                a-=nums[i];
                continue;
            }
            ll need=(nums[i]-a+k-1)/k;
            a=need*k-(nums[i]-a);
            c+=need;
        }
        ans=((__int128)c*(c+1)/2)%mod;
        return (int)ans;
    }
};