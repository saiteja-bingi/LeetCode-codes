// Last updated: 5/8/2026, 4:12:42 pm
1class Solution {
2public:
3    void dfs(auto &adj,auto &vis,auto& sus,int u){
4        if(vis[u]) return;
5        sus[u]=1;
6        vis[u]=1;
7        for(auto e:adj[u]){
8            dfs(adj,vis,sus,e);
9        }
10    }
11    vector<int> remainingMethods(int n, int k, vector<vector<int>>& inv) {
12        vector<vector<int>>adj(n);
13        vector<int>vis(n),sus(n,0);
14        for(auto it:inv){
15            adj[it[0]].push_back(it[1]);
16        }
17        dfs(adj,vis,sus,k);
18        bool ok=0;
19        for(auto& e:inv){
20            if(!sus[e[0]]&&sus[e[1]]){
21                ok=1;
22                break;
23            }
24        }
25        vector<int>ans;
26        if(ok){
27            for(int i=0;i<n;i++) ans.push_back(i);
28            return ans;
29        }
30        for(int i=0;i<n;i++){
31            if(!sus[i]) ans.push_back(i);
32        }
33        return ans;
34        
35    }
36};