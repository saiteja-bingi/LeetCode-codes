// Last updated: 26/4/2026, 11:32:53 am
1class Solution {
2public:
3    /*
4        dfs from every point
5        go all 4 directions not visited
6    */
7    int dx[4]={0,0,-1,1};
8    int dy[4]={1,-1,0,0};
9    bool dfs(auto& grid,int i,int j,auto& vis,int a,int b){
10        int n=grid.size();
11        int m=grid[0].size();
12        vis[i][j]=true;
13        for(int k=0;k<4;k++){
14            int x=i+dx[k];
15            int y=j+dy[k];
16            if(x>=0&&y>=0&&x<n&&y<m&&grid[x][y]==grid[i][j]){
17                // if(x==a&&y==b&&c>=2) return true;
18                if(!vis[x][y]){
19                    if(dfs(grid,x,y,vis,i,j)) return true;
20                }
21                else if(x!=a||y!=b) return true;
22            }
23        }
24        return false;
25    }
26    bool containsCycle(vector<vector<char>>& grid) {
27        int n=grid.size();
28        int m=grid[0].size();
29        vector<vector<bool>>vis(n,vector<bool>(m,false));
30        for(int i=0;i<n;i++){
31            for(int j=0;j<m;j++){
32                if(!vis[i][j]){
33                    if(dfs(grid,i,j,vis,-1,-1)) return true;
34                }
35            }
36        }
37        return false;
38    }
39};