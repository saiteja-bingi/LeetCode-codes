// Last updated: 15/04/2026, 00:45:49
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& grid, int sr, int sc, int color) {
        int n=grid.size();
        int m=grid[0].size();

        int inic=grid[sr][sc];
        if(inic == color) return grid;
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,1,-1};

        queue<pair<int,int>>q;
        // vector<vector<bool>>vis(n,vector<bool>(m,false));

        q.push({sr,sc});
        // vis[sr][sc]=true;
        grid[sr][sc]=color;

        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                auto[x,y]=q.front();
                q.pop();
                for(int j=0;j<4;j++){
                    int ni=x+dx[j];
                    int nj=y+dy[j];
                    if(ni>=0&&nj>=0&&ni<n&&nj<m){
                        if(grid[ni][nj]==inic){
                            // vis[ni][nj]=true;
                            grid[ni][nj]=color;
                            q.push({ni,nj});
                        }
                    }
                }
            }
        }
        return grid;
    }
};