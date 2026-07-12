// Last updated: 12/7/2026, 11:19:08 pm
1class DSU{
2public:
3    vector<int>par,sz;
4    DSU(int n){
5        par.resize(n);
6        sz.assign(n,1);
7        iota(par.begin(),par.end(),0);
8    }
9    int find(int x){
10        if(par[x]==x) return x;
11        return par[x]=find(par[x]);
12    }
13    void unite(int x,int y){
14        x=find(x),y=find(y);
15        if(x==y) return;
16        if(sz[x]<sz[y]) swap(x,y);
17        par[y]=x;
18        sz[x]+=sz[y];
19    }
20    bool same(int x,int y){
21        return find(x)==find(y);
22    }
23    int xsize(int x){
24        return sz[find(x)];
25    }
26};
27
28class Solution {
29public:
30    vector<bool>vis;
31    bool dfs(auto& adj,int i,int sz){
32        vis[i]=true;
33        bool ok=adj[i].size()==sz;
34        for(auto x:adj[i]){
35            if(!vis[x]){
36                ok&=dfs(adj,x,sz);
37            }
38        }
39        return ok;
40    }
41    int countCompleteComponents(int n, vector<vector<int>>& edges) {
42        DSU dsu(n);
43        vector<vector<int>>adj(n);
44        vis.assign(n,false);
45        vector<int>temp(n);
46        for(auto &e:edges){
47            adj[e[0]].push_back(e[1]);
48            adj[e[1]].push_back(e[0]);
49            dsu.unite(e[0],e[1]);
50        }
51        int ans=0;
52        for(int i=0;i<n;i++){
53            if(vis[i]) continue;
54            int r=dsu.xsize(i);
55            ans+=dfs(adj,i,r-1);
56        }
57        return ans;
58    }
59};