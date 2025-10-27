// Last updated: 10/27/2025, 7:09:50 PM
// __LC_TEMPLATE_START__::cpp
// <<<<<<<<------------------------>>>>>>>>------------------------>>>>>>>>>>
#include <bits/stdc++.h>
using namespace std;

// ------------------- Type Aliases -------------------
#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define vc vector<char>
#define vvi vector<vi>
#define vvl vector<vll>

#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()

#define mapii map<int,int>
#define mapll map<long long,long long>
#define mapci map<char,int>
#define unmap unordered_map<int,int>
#define unmapll unordered_map<ll,ll>

#define pii pair<int,int>
#define pll pair<long long,long long>

#define str string

#define fi first
#define se second

// ------------------- Loop Macros -------------------
#define ffor(i,a,b) for(int i=(a);i<(b);i++)
#define forr(i,a,b) for(int i=(a);i>(b);i--)
#define rep(i,n) for(int i=1;i<(n);i++)
#define repn(i,n) for(int i=1;i<=(n);i++)
#define repr(i,n) for(int i=(n)-1;i>=0;i--)

// ------------------- Misc Macros -------------------
#define fixed(n) fixed << setprecision(n)
#define ceil_div(n,m) (((n) + (m) - 1) / (m))

// ------------------- Fast I/O -------------------
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

const int MOD = 1e9 + 7;

// ------------------- Modular Operations -------------------
ll mod_add(ll a, ll b) { return (a + b) % MOD; }
ll mod_sub(ll a, ll b) { return (a - b + MOD) % MOD; }
ll mod_mul(ll a, ll b) { return (a * b) % MOD; }

// <<<<<<<<<-------------------- SOLVE FUNCTION -------------------->>>>>>>
int solve(vector<vector<int>>&dp,vector<vector<int>>&grid,int n,int m) {
    if(n<0||m<0) return INT_MAX;
    if(n==0&&m==0){
        return grid[0][0];
    }
    if(dp[n][m]!=-1){
        return dp[n][m];
    }
    ll up=0,left=0,ans=grid[n][m];
    up=solve(dp,grid,n-1,m);
    left=solve(dp,grid,n,m-1);
    dp[n][m]=ans+min(up,left);
    return dp[n][m];
}

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        // int ans=solve(dp,grid,n-1,m-1);
        // return ans;
        dp[0][0]=grid[0][0];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0&&j==0){
                    dp[i][j]=grid[i][j];
                }
                else{
                    ll left=INT_MAX,up=INT_MAX;
                    if(j>0) left=dp[i][j-1];
                    if(i>0) up=dp[i-1][j];
                    dp[i][j]=grid[i][j]+min(left,up);
                }
            }
        }
        return dp[n-1][m-1];
    }
};