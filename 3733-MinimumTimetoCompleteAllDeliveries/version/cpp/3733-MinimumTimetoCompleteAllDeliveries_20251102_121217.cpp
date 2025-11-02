// Last updated: 11/2/2025, 12:12:17 PM
#define ll long long
class Solution {
public:

    bool possible(ll t,vector<int>& d, vector<int>& r){
        ll rt1=t-t/r[0];
        ll rt2=t-t/r[1];
        ll lcm=(r[0]*r[1])/__gcd(r[0],r[1]);
        ll total=t-t/lcm;
        return rt1>=d[0]&&rt2>=d[1]&&(d[0]+d[1])<=total;

    }
    long long minimumTime(vector<int>& d, vector<int>& r) {
        ll l=1,ri=1LL*d[0]*r[0]+1LL*d[1]*r[1];
        ll ans=0;
        while(l<ri){
            ll mid=(l+ri)/2;
            if(possible(mid,d,r)){
                ans=mid;
                ri=mid;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};