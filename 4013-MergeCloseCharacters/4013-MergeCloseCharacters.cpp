// Last updated: 15/04/2026, 00:43:34
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
    string mergeCharacters(string s, int k) {
        int n=s.size();
        string ans="";
        mapll mp;
        ffor(i,0,n){
            if(!mp.count(s[i])){
                ans+=s[i];
                mp[s[i]]=i;
            }
            else{
                if(i-mp[s[i]]>k){
                    mp[s[i]]=i;
                    ans+=s[i];
                }
                else{
                    for(auto &[x,y]:mp){
                        y++;
                    }
                }
            }
        }
        return ans;
    }
};