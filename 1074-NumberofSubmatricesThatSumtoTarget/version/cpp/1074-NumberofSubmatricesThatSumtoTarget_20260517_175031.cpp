// Last updated: 17/5/2026, 5:50:31 pm
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
17            for(int j=0;j<m;j++){
18                for(int rc=0;i-rc>=0;rc++){
19                    for(int cc=0;j-cc>=0;cc++){
20                        int ni=i-rc,nj=j-cc;
21                        ll sum=pre[i+1][j+1]-pre[ni][j+1]-pre[i+1][nj]+pre[ni][nj];
22                        if(sum==target) ans++;
23                    }
24                }
25            }
26        }
27        return ans;
28    }
29};