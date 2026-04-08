// Last updated: 08/04/2026, 23:54:40
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<long long>
#define vc vector<char>
#define vvl vector<vll>
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define mapll map<long long,long long>
#define mapcl map<char,long long>
#define unmapll unordered_map<ll,ll>
#define pll pair<long long,long long>
#define str string
#define fi first
#define se second
#define ffor(i,a,b) for(int i=(a);i<(b);i++)
#define forr(i,a,b) for(int i=(a);i>=(b);i--)
#define ceil_div(n,m) (((n) + (m) - 1) / (m))
#define take(v,n)   for(int j=0;j<n;j++) cin>>v[j];
#define give(v,n)   for(int j=0;j<n;j++) cout<<v[j]<<' ';
#define lb lower_bound
#define ub upper_bound
#define yes cout << "YES\n"
#define no cout << "NO\n"

#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const int mod = 1e9 + 7;

class Solution {
public:
    vector<long long> fact, invfact;

// <--------------- Utility Functions------------------>>>
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

    void precompute(int n) {
        fact[0] = 1;
        for(int i = 1; i <=n; i++) {
            fact[i] = (fact[i-1] * (ll)i) % mod;
        }
        
        // Inverse factorials for division
        invfact[n] = binpow(fact[n], mod - 2);
        for(int i = n-1; i >= 0; i--) {
            invfact[i] = (invfact[i+1] * (ll)(i+1)) % mod;
        }
    }

    ll nCr(ll n, ll r) {
        if(r > n || r < 0) return 0;
        return (fact[n] * invfact[r] % mod) * invfact[n-r] % mod;
    }

    ll nPr(ll n, ll r) {
        if(r > n || r < 0) return 0;
        return (fact[n] * invfact[n-r]) % mod;
    }


    /*
        0 1 2 
          ^ 
        K=0=>{
            0->R,1->L
        }

        if k==0:
            then only zero people to see
            so all of them are fixed
            n-1 is ans
        if k==1:
            1)from left side i choose only one L
            2)from right side i choose only one R

            how many cna i do with 1:


    */



    int countVisiblePeople(int n, int pos, int k) {
        fact.resize(n+1);
        invfact.resize(n+1);
        precompute(n); 

        long long ans=0;
        for(int p=0;p<=k;p++){
            if(pos>=p&&(n-pos-1)>=(k-p)){
                ans=(ans+(nCr(pos,p)*nCr(n-pos-1,k-p))%mod)%mod;
            }
        }
        return (ans*2)%mod;
    }
};