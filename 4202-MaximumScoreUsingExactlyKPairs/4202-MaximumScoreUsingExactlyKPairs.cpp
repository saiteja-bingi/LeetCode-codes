// Last updated: 09/02/2026, 21:05:06
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

const int mod = 1e9 + 7;




ll findsol(vector<int>&a, vector<int>&b,ll i,ll j,ll k,map<pair<ll,ll>,ll>& dp){
    if(k==0) return 0;
    if(min(a.size()-i,b.size()-j)<k) return -1e18;
    if(i>=a.size()||j>=b.size()) return -1e18;
    ll key=((j<<7)|(k));
    if(dp.count({i,key})) return dp[{i,key}];
    ll x=(1ll*a[i]*b[j])+findsol(a,b,i+1,j+1,k-1,dp);
    ll y=findsol(a,b,i,j+1,k,dp);
    ll z=findsol(a,b,i+1,j,k,dp);
    return dp[{i,key}]=max({x,y,z});
}


class Solution {
public:
    long long maxScore(vector<int>& a, vector<int>& b, int r) {
        ll n=a.size();
        ll m=b.size();
        vector<vector<vector<ll>>>dp(n+1,vector<vector<ll>>(m+1,vector<ll>(r+1,-1e18)));
        ffor(i,0,n+1){
            ffor(j,0,m+1){
                dp[i][j][0]=0;
            }
        }
        ffor(i,1,n+1){
            ffor(j,1,m+1){
                ffor(k,1,r+1){
                    ll x=(1ll*a[i-1]*b[j-1])+dp[i-1][j-1][k-1];
                    ll y=dp[i][j-1][k];
                    ll z=dp[i-1][j][k];
                    dp[i][j][k]=max({x,y,z});
                }
            }
        }
        return dp[n][m][r];

    }
};