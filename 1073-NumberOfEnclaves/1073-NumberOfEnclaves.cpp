// Last updated: 15/04/2026, 00:45:27
class Solution {
public:
    void dfs(auto&grid,int i,int j){
        int n=grid.size();
        int m=grid[0].size();
        if(i<0||j<0||i>=n||j>=m||grid[i][j]!=1) return;
        grid[i][j]=-1;
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,1,-1};
        for(int x=0;x<4;x++){
            int ni=i+dx[x];
            int nj=j+dy[x];
            dfs(grid,ni,nj);
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        for(int i=0;i<n;i++){
            if(grid[i][0]) dfs(grid,i,0);
            if(grid[i][m-1]) dfs(grid,i,m-1);
        }
        for(int i=0;i<m;i++){
            if(grid[0][i] ) dfs(grid,0,i);
            if(grid[n-1][i]) dfs(grid,n-1,i);
        }
        int c=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) c++;
            }
        }
        return c;
    }
};