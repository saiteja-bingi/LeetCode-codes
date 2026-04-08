// Last updated: 08/04/2026, 23:55:10
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

map<pair<ll,ll>,ll>mp;
ll find(string &s,int ec,int fc,vll&presum,int i,int j){
    if(i >= j){
        if(s[i] == '0') return fc;
        return ec;
    }
    if(mp.count({i,j})) return mp[{i,j}];
    // count ones
    ll ones=presum[j]-((i-1>=0)?presum[i-1]:0);

    if((j-i+1)%2!=0){
        if(ones==0){
            return fc;
        }
        return ones*(j-i+1)*ec;
    }
    // no split
    ll s1=((ones==0)?fc:ones*(j-i+1)*ec);

    // split
    ll mid=(i+j)/2;
    ll s2=find(s,ec,fc,presum,i,mid)+find(s,ec,fc,presum,mid+1,j);
    return mp[{i,j}]= min(s1,s2);
}


class Solution {
public:
    long long minCost(string s, int ec, int fc) {
        mp.clear();
        ll n=s.size();
        vll presum(n,0);
        presum[0]=(s[0]=='1'?1:0);
        ffor(i,1,n){
            presum[i]=presum[i-1]+(s[i]=='1'?1:0);
        }
        if(n%2!=0){
            // odd length 
            // no ones
            if(presum[n-1]==0) return fc;
            return n*presum[n-1]*ec;
        }

        // no div
        ll s1=((presum[n-1]==0)?fc:n*presum[n-1]*ec);
        // divide and conquer
        ll a1=find(s,ec,fc,presum,0,(n-1)/2);
        ll a2=find(s,ec,fc,presum,(n-1)/2+1,n-1);
        return min(s1,a1+a2);
    }
};







