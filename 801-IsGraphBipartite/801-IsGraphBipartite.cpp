// Last updated: 15/04/2026, 00:45:45
class Solution {
public:
    vector<int>col;
    bool dfs(auto& graph,int u){
        for(auto v:graph[u]){
            if(col[v]==-1){
                col[v]=col[u]^1;
                if(dfs(graph,v)) return true;
            }
            else if(col[v]==col[u]) return true;
        }
        return false;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        col.resize(n,-1);
        for(int i=0;i<n;i++){
            if(col[i]!=-1) continue;
            col[i]=0;
            if(dfs(graph,i)) return false;
        }
        return true;
    }
};