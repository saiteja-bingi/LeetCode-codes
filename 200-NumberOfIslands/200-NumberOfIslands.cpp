// Last updated: 15/04/2026, 00:46:56
class Solution {
public:
    // map<pair<int,int,int>vis;

    void dfs(auto &grid,int i,int j){
        int n=grid.size(),m=grid[0].size();
        if(i<0||i>=n||j<0||j>=m||grid[i][j]!='1') return;
        grid[i][j]='x';
        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,1,-1};
        for(int x=0;x<4;x++){
            dfs(grid,i+dx[x],j+dy[x]);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    dfs(grid,i,j);
                    ans++;
                }
            }
        }
        return ans;
    }
};