// Last updated: 17/5/2026, 9:34:53 pm
1#define ll long long
2class Solution {
3public:
4    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
5        ll n=matrix.size();
6        ll m=matrix[0].size();
7        vector<vector<ll>>pre(n+1,vector<ll>(m+1,0));
8        for(ll i=0;i<n;i++){
9            ll c=0;
10            for(ll j=0;j<m;j++){
11                c+=matrix[i][j];
12                pre[i+1][j+1]=c+pre[i][j+1];
13            }
14        }
15        int ans=0;
16        for(int i=0;i<n;i++){
17            vector<ll>ps(m+1,0);
18            for(int ci=i;ci<n;ci++){
19                for(int j=0;j<m;j++){
20                    ps[j]+=matrix[ci][j];
21                }
22                unordered_map<ll,ll>mp;
23                mp[0]=1;
24                ll pref=0;
25                for(int j=0;j<m;j++){
26                    pref+=ps[j];
27                    ans+=mp[pref-target];
28                    mp[pref]++;
29                }
30            }
31        }
32        return ans;
33    }
34};