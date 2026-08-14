// Last updated: 14/8/2026, 11:40:17 pm
1#define ll long long
2class Solution {
3public:
4    vector<vector<ll>>vis;
5    ll dfs(auto&adj, ll src,ll dst,ll k){
6        if(src==dst){
7            return 0;
8        }
9        if(k==0) return -1;
10        if(vis[src][k]!=-2) return vis[src][k];
11        ll ans=INT_MAX;
12        for(auto &x:adj[src]){
13            ll d=-1;
14            if(k-1>=0) d=dfs(adj,x[0],dst,k-1);
15            if(d!=-1) ans=min(ans,d+x[1]);
16        }
17        return vis[src][k]=(ans==INT_MAX)?-1:ans;
18    }
19    int findCheapestPrice(int n, vector<vector<int>>& flights,int src, int dst, int k) {
20        vector<vector<vector<ll>>>adj(n);
21        vis.assign(n, vector<ll>(k + 2, -2));
22        for(auto &x:flights){
23            adj[x[0]].push_back({x[1],x[2]});
24        }
25        return dfs(adj,src,dst,k+1);
26
27    }
28};