// Last updated: 5/8/2026, 4:07:29 pm
1class Solution {
2public:
3    void dfs(auto &adj,auto &vis,auto& sus,int u,auto & reach){
4        if(vis[u]) return;
5        reach.push_back(u);
6        sus[u]=1;
7        vis[u]=1;
8        for(auto e:adj[u]){
9            dfs(adj,vis,sus,e,reach);
10        }
11    }
12    vector<int> remainingMethods(int n, int k, vector<vector<int>>& inv) {
13        vector<vector<int>>adj(n),par(n);
14        vector<int>vis(n),sus(n,0),reach;
15        for(auto it:inv){
16            adj[it[0]].push_back(it[1]);
17            par[it[1]].push_back(it[0]);
18        }
19        dfs(adj,vis,sus,k,reach);
20        bool ok=false;
21        for(auto it:reach){
22            for(auto m:par[it]){
23                if(sus[it]&&!sus[m]){
24                    ok=true;
25                    break;
26                }
27            }
28        }
29        vector<int>ans;
30        if(ok){
31            for(int i=0;i<n;i++) ans.push_back(i);
32            return ans;
33        }
34        for(int i=0;i<n;i++){
35            if(!sus[i]) ans.push_back(i);
36        }
37        return ans;
38        
39    }
40};