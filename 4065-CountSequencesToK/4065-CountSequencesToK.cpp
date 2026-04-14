// Last updated: 15/04/2026, 00:43:24
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


class Solution {
public:
    
    int countSequences(vector<int>& nums, long long k) {
        ll n=nums.size();
        map<pll,ll>dp;
        dp[{1,1}]=1;
        for(ll i=1;i<=n;i++){
            map<pll,ll>temp;
            for(auto &it:dp){
                ll num=it.fi.fi;
                ll den=it.fi.se;
                ll c=it.se;
                temp[{num*nums[i-1],den}]+=c;
                temp[{num,den*nums[i-1]}]+=c;
                temp[{num,den}]+=c;
            }
            dp=temp;
        }
        ll c=0;
        for(auto &it:dp){
            ll num=it.fi.fi;
            ll den=it.fi.se;
            if(k==1.0*num/den){
                c+=it.se;
            }
        }
        return c;
    }
};




