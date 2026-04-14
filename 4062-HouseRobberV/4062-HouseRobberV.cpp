// Last updated: 15/04/2026, 00:43:26
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

    ll find(vector<int>& arr,ll j,ll i){
        // vll dp(arr.size()+1,0);
        // dp[j]=arr[j];
        ll p1=0,p2=0,cur=0;
        for(ll k=j+1;k<=i&&k<=arr.size();k++){
            ll a=arr[k-1],b=0;
            if(k-2>=0) a+=p2;
            if(k-1>=0) b=p1;
            cur=max(1ll*a,1ll*b);
            p2=p1;
            p1=cur;
        }
        return cur;
    }
    
    long long rob(vector<int>& nums, vector<int>& col) {
        ll n=nums.size();
        ll i=0,j=0;
        ll sum=0;
        while(j<n){
            ll maxi=nums[j];
            ll i=j+1;
            while(i<n&&col[i-1]==col[i]){
                i++;
            }
            // vll dp(n+1,-1);
            // cout<<j<<" "<<i<<endl;
            maxi=find(nums,j,i);
            sum+=maxi;
            j=i;
        }
        return sum;
    }
};