// Last updated: 15/04/2026, 00:43:35
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

#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const int mod = 1e9 + 7;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k, int m) {
        ll leftk=0;
        ll leftkm=0;
        ll nkm=0;
        ll ans=0;
        unmapll mpk,mpkm;
        for(int r=0;r<nums.size();r++){
            mpk[nums[r]]++;
            while(mpk.size()>k){
                mpk[nums[leftk]]--;
                if(mpk[nums[leftk]]==0) mpk.erase(nums[leftk]);
                leftk++;
            }

            mpkm[nums[r]]++;
            if(mpkm[nums[r]]==m) nkm++;
            while(nkm>=k){
                if(mpkm[nums[leftkm]]==m) nkm--;
                mpkm[nums[leftkm]]--;
                leftkm++;
            }
            if(leftk<leftkm) ans+=leftkm-leftk;
        }
        return ans;
    }
};