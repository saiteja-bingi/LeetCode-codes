// Last updated: 08/04/2026, 23:54:30

#define ll long long
int mod=1e9+7;
/*
    two pairs then good integer
    all good in between  <=n
*/

class Solution {
public:
    ll binpow(ll a, ll b) {
        ll res = 1;
        a %= mod;
        while(b > 0) {
            if(b & 1) res = (res * a) % mod;
            a = (a * a) % mod;
            b >>= 1;
        }
        return res;
    }
    int find(int i, int j){
        return binpow(i,3)+binpow(j,3);
    }
    vector<int> findGoodIntegers(int n) {
        set<int> ans;
        map<int,int>mp;
        for(int i=1;i*i*i<=n;i++){
            for(int j=i+1;j*j*j+i*i*i<=n;j++){
                int k=find(i,j);
                if(mp.count(k)) ans.insert(k);
                mp[k]++;
            }
        }
        vector<int>temp(ans.begin(),ans.end());
        return temp;
    }
};