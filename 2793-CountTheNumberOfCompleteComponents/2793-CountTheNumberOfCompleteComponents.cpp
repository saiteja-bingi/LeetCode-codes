// Last updated: 15/04/2026, 00:44:39
class Solution {
public:

    vector<bool>vis;
    void dfs(auto&adj,int i,auto& ans){
        ans.push_back(i);
        vis[i]=true;
        for(auto v:adj[i]){
            if(!vis[v]){
                dfs(adj,v,ans);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vis.resize(n,false);
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                vector<int>temp;
                dfs(adj,i,temp);
                ans.push_back(temp);
            }
        }
        int c=0;
        for(auto arr:ans){
            int m=arr.size();
            bool y=true;
            for(auto it:arr){
                if(adj[it].size()!=m-1){
                    y=false;
                    break;
                }
            }
            if(y) c++;
        }
        return c;
    }
};