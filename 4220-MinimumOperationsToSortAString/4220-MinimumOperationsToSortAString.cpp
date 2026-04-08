// Last updated: 08/04/2026, 23:54:58
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
    int minOperations(string s) {
        int n=s.size();
        if(is_sorted(all(s))){
            return 0;
        }
        if(n==2) return -1;
        bool y=true;
        bool h1=true;
        ffor(i,1,n){
            if(s[0]>s[i]) y=false;
            if(s[0]<s[i]) h1=false;
        }
        bool k=true;
        bool h2=true;
        ffor(i,0,n-1){
            if(s[n-1]<s[i]) k=false;
            if(s[n-1]>s[i]) h2=false;
        }
        if(y||k) return 1;
        if(h1&&h2){
            ll c1=0,c2=0;
            ffor(i,0,n){
                if(s[i]==s[0]) c1++;
                if(s[i]==s[n-1]) c2++;
            }
            if(c1==1&&c2==1) return 3;
        }
        return 2;
    }
};