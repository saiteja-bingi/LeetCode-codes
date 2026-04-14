// Last updated: 15/04/2026, 00:46:52
class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto e : edges){
            adj[e[1]].push_back(e[0]);
        }
        vector<int>indegree(n);
        for(int i=0;i<n;i++){
            for(auto it:adj[i]) indegree[it]++;
        }
        queue<int>q;
        for(int i=0;i<n;i++) if(indegree[i]==0) q.push(i);
        vector<int>ans;
        // int ans=0;
        while(!q.empty()){
            int x=q.front();
            q.pop();
            ans.push_back(x);
            for(auto v:adj[x]){
                indegree[v]--;
                if(indegree[v]==0) q.push(v);
            }
        }
        if(ans.size()<n) return {};
        return ans;
    }
};