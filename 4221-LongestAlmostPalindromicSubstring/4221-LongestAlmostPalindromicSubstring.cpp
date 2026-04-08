// Last updated: 08/04/2026, 23:54:57
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
    ll find(string&s,ll i,ll j){
        ll n=s.size();
        ll c=0;
        while(i>=0&&j<n&&s[i]==s[j]){
            c+=2;
            i--;
            j++;
        }
        return c;
    }
    int almostPalindromic(string s) {
        ll n=s.size();
        ll ans=0;
        for(ll c=0;c<s.size();c++){
            ll i=c-1,j=c+1;
            ll co=1;
            while(i>=0&&j<n){
                if(s[i]!=s[j]){
                    ll a=1+find(s,i,j+1);
                    ll b=1+find(s,i-1,j);
                    co+=max(a,b);
                    break;
                }
                else if(s[i]==s[j]) co+=2;
                i--;
                j++;
            }
            if(j>=n&&i>=0||i<0&&j<n) co++;
            
            ans=max(ans,co);
            i=c;j=c+1;co=0;
            while(i>=0&&j<n){
                if(s[i]!=s[j]){
                    ll a=1+find(s,i,j+1);
                    ll b=1+find(s,i-1,j);
                    co+=max(a,b);
                    break;
                }
                else if(s[i]==s[j]) co+=2;
                i--;
                j++;
            }
            // if(j>=n&&i>=0) cout<<c<<endl;
            if(j>=n&&i>=0||i<0&&j<n) co++;
            
            ans=max(ans,co);
            // cout<<ans<<endl;
        }
        return ans;
    }
};