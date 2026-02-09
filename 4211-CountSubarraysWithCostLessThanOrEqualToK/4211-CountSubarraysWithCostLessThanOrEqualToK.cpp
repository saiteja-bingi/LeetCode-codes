// Last updated: 09/02/2026, 21:05:08
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
    long long countSubarrays(vector<int>& nums, long long k) {
        ll n=nums.size();
        deque<ll>dqmin,dqmax;
        ll i=0,j=0;
        ll ans=0;
        while(j<n){
            while(!dqmin.empty()&&nums[dqmin.back()]>nums[j]) dqmin.pop_back();
            dqmin.pb(j);
            while(!dqmax.empty()&&nums[dqmax.back()]<nums[j]) dqmax.pop_back();
            dqmax.pb(j);
            ll sum=(nums[dqmax.front()]-nums[dqmin.front()])*(j-i+1);
            while(i<=j&&sum>k){
                if(dqmin.front()==i) dqmin.pop_front();
                if(dqmax.front()==i) dqmax.pop_front();
                i++;
                sum=(nums[dqmax.front()]-nums[dqmin.front()])*(j-i+1);
            }
            ans+=(j-i+1);
            j++;
        }
        return ans;
    }
};









