// Last updated: 15/04/2026, 00:43:30
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
    string maximumXor(string s, string t) {
        ll n=t.size();
        string ans="";
        map<char,ll>mp;
        for(auto it:t) mp[it]++;
        for(ll i=0;i<n;i++){
            if(s[i]=='0'){
                if(mp['1']>0){mp['1']--;
                ans+="1";}
                else ans+="0";
            }
            else{
                if(mp['0']>0){
                    mp['0']--;
                    ans+="1";
                }
                else ans+="0";
            }
        }
        return ans;
    }
};