// Last updated: 09/02/2026, 21:05:05
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
    int dominantIndices(vector<int>& nums) {
        ll n=nums.size();
        vll presum(n);
        presum[n-1]=nums[n-1];
        ll sum=nums[n-1];
        forr(i,n-2,0){
            presum[i]=(sum+nums[i])/(n-i);
            sum+=nums[i];
        }
        int c=0;
        ffor(i,0,n-1){
            if(nums[i]>presum[i]) c++;
        }
        return c;
    }
};

















