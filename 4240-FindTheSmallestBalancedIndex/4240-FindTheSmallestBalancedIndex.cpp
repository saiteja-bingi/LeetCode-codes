// Last updated: 08/04/2026, 23:54:47
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
class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        int n=nums.size();
        vll pre(n,0),suf(n,0);
        pre[0]=nums[0];
        ffor(i,1,n) pre[i]=pre[i-1]+nums[i];
        suf[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            if((__int128)suf[i+1]*nums[i]>LLONG_MAX) suf[i]=LLONG_MAX;
            else suf[i]=suf[i+1]*nums[i];
        }
        for(int i=0;i<n;i++){
            if(i==0){
                if(i+1<n&&suf[i+1]==0) return i;
            }
            else if(i==n-1){
                if(i-1>=0&&pre[i-1]==1) return i;
            }
            else if(suf[i+1]==pre[i-1]) return i;
        }
        return -1;
    }
    
};


















