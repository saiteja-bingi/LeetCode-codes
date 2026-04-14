// Last updated: 15/04/2026, 00:45:07
class Solution {
public:
    using ll=long long;
    int concatenatedBinary(int n) {
        ll ans=0;
        ll mod=1e9+7;
        for(ll i=1;i<=n;i++){
            bitset<32>b(i);
            string s=b.to_string();
            ll j=0;
            while(s[j]=='0') j++;
            // cout<<s<<" "<<j<< endl;
            ll sz=s.size()-j;
            // cout<<(1ll<<sz)<<" "<<sz<<endl;
            ans=((ans*(1ll<<sz))%mod+i)%mod;
        }
        return ans;
    }
};