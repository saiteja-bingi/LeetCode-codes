// Last updated: 08/04/2026, 23:54:53
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

class Solution {
public:
    bool isDigitorialPermutation(int n) {
        vll fact(10);
        fact[0]=1;
        for(ll i=1;i<10;i++) fact[i]=fact[i-1]*i;
        
        ll k=n;
        ll sum=0;
        map<ll,ll>mp1,mp2;
        while(k>0){
            sum+=fact[k%10];
            mp1[k%10]++;
            k/=10;
        }
        cout<<sum<<endl;
        k=sum;
        while(k>0){
            mp2[k%10]++;
            k/=10;
        }
        if(mp1.size()!=mp2.size()) return false;
        for(auto&[x,y]:mp2){
            cout<<mp1[x]<<endl;
            if(y!=mp1[x]) return false;
        }
        return true;
    }
};









