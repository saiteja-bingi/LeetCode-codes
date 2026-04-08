// Last updated: 08/04/2026, 23:54:50
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
class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        unmapll mp;
        ffor(i,0,n){
            mp[nums[i]]++;
        }
        int x=-1,y=-1;
        ffor(i,0,n){
            if(x==-1) x=nums[i];
            else if(mp[nums[i]]!=mp[x]){
                y=nums[i];
                break;
            }
        }
if(y==-1) return {-1,-1};
return {x,y};
    }
};








