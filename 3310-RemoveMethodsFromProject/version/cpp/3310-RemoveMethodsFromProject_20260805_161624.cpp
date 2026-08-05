// Last updated: 5/8/2026, 4:16:24 pm
1class Solution {
2public:
3    vector<int> remainingMethods(int n, int k, vector<vector<int>>& inv) {
4        vector<vector<int>>adj(n);
5        vector<int>sus(n,0);
6        for(auto it:inv){
7            adj[it[0]].push_back(it[1]);
8        }
9        queue<int>q;
10        q.push(k);
11        sus[k]=1;
12        while(!q.empty()){
13            for(auto e:adj[q.front()]){
14                if(!sus[e]){
15                    sus[e]=1;
16                    q.push(e);
17                }
18            }
19            q.pop();
20        }
21
22        bool ok=0;
23        for(auto& e:inv){
24            if(!sus[e[0]]&&sus[e[1]]){
25                ok=1;
26                break;
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