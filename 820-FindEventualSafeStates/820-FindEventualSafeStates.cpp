// Last updated: 15/04/2026, 00:45:43
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>>rev(n);
        for(int i=0;i<n;i++){
            for(auto v:graph[i]){
                rev[v].push_back(i);
            }
        }
        graph=rev;
        vector<int>indegree(n);
        for(int i=0;i<n;i++){
            for(auto v:graph[i]) indegree[v]++;
        }
        vector<int>ans;
        queue<int>q;
        for(int i=0;i<n;i++) if(indegree[i]==0) q.push(i);
        while(!q.empty()){
            int u=q.front();
            q.pop();
            ans.push_back(u);
            for(auto v:graph[u]){
                indegree[v]--;
                if(indegree[v]==0){
                    q.push(v);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};