// Last updated: 08/04/2026, 23:54:48
class Solution {
public:
    using ll=long long;
    ll mod=1e9+7;
    ll binpow(ll a ,ll b){
        ll res=1;
        a%=mod;
        while(b>0){
            if(b&1) res=(res*a)%mod;
            a=(a*a)%mod;
            b>>=1;
        }
        return res%mod;
    }
    int sumOfNumbers(int l, int r, int k) {
        ll num=binpow(r-l+1,k-1);
        ll sum=r*(r+1)/2;
        if(l!=0)sum-=(l-1)*(l)/2;
        ll vv=(binpow(10,k)-1+mod)%mod;
        vv = vv * binpow(9,mod-2) % mod;
        return (num*sum%mod)*vv%mod;
    }
};