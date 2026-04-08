// Last updated: 08/04/2026, 23:54:59
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<long long>
#define vii vector<int>
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
    vii solve(vii&nums,int even){
        int c=0;
        int mi=INT_MAX;
        int ma=INT_MIN;
        int n=nums.size();
        for(auto num:nums){
            if(((num&1)&&even)||(!(num&1)&&!even)){
                c++;
                ma=max(ma,num-1);
                mi=min(mi,num+1);
            }
            else{
                ma=max(ma,num);
                mi=min(mi,num);
            }
            even=!even;
        }
        return {c,ma-mi};
    }
    vector<int> makeParityAlternating(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return {0,0};
        unordered_set<int> mp(all(nums));
        if(mp.size()==1){
            return {(int)n/2,1};
        }
        vii arr1=solve(nums,0);
        vii arr2=solve(nums,1);
        if(arr1[0]==arr2[0]) return (arr1[1]<arr2[1])?arr1:arr2;
        return (arr1[0]<arr2[0])?arr1:arr2;
    }
    
};















