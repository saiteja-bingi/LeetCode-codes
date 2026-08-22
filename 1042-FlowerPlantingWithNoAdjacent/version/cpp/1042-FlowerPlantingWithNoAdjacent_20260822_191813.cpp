// Last updated: 22/8/2026, 7:18:13 pm
1class Solution {
2public:
3    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
4        vector<vector<int>>adj(n);
5        for(auto x:paths){
6            x[0]--;
7            x[1]--;
8            adj[x[0]].push_back(x[1]);
9            adj[x[1]].push_back(x[0]);
10        }
11        vector<int>ans(n,0);
12        for(int u=0;u<n;u++){
13            bool used[5]={};
14            for(auto v:adj[u]){
15                if(ans[v]!=0) used[ans[v]]=1;
16            }
17            for(int c=1;c<=4;c++){
18                if(!used[c]){
19                    ans[u]=c;
20                    break;
21                }
22            }
23        }
24        return ans;
25    }
26};