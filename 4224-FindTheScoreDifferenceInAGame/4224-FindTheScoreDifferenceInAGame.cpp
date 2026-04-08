// Last updated: 08/04/2026, 23:54:54
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
    int scoreDifference(vector<int>& nums) {
        ll c1=0,c2=0;
        bool f=true;
        for(ll i=0;i<nums.size();i++){
            if(nums[i]%2!=0) f=!f;
            if((i+1)%6==0) f=!f;
            if(f) c1+=nums[i];
            else c2+=nums[i];
        }
        return c1-c2;
    }
};















