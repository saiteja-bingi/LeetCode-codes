// Last updated: 29/4/2026, 5:05:43 pm
1class Solution {
2public:
3    bool hasValidPath(vector<vector<int>>& grid) {
4        int m = grid.size(), n = grid[0].size();
5        
6        vector<vector<vector<int>>> dirs = {
7            {},
8            {{0,-1},{0,1}},
9            {{-1,0},{1,0}},
10            {{0,-1},{1,0}},
11            {{0,1},{1,0}},
12            {{0,-1},{-1,0}},
13            {{0,1},{-1,0}}
14        };
15        
16        queue<pair<int,int>> q;
17        vector<vector<bool>> vis(m, vector<bool>(n, false));
18        
19        q.push({0,0});
20        vis[0][0] = true;
21        
22        while(!q.empty()) {
23            auto [r,c] = q.front();
24            q.pop();
25            
26            if(r == m-1 && c == n-1) return true;
27            
28            for(auto &d : dirs[grid[r][c]]) {
29                int nr = r + d[0];
30                int nc = c + d[1];
31                
32                if(nr < 0 || nc < 0 || nr >= m || nc >= n || vis[nr][nc]) continue;
33                
34              
35                for(auto &back : dirs[grid[nr][nc]]) {
36                    if(nr + back[0] == r && nc + back[1] == c) {
37                        vis[nr][nc] = true;
38                        q.push({nr,nc});
39                    }
40                }
41            }
42        }
43        
44        return false;
45    }
46};