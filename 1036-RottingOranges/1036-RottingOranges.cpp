// Last updated: 15/04/2026, 00:45:32
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m));
        queue<pair<int,int>>q;
        int fresh=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2) {
                    q.push({i,j});
                    vis[i][j]=1;
                }
                else if(grid[i][j]==1) fresh++;
            }
        }
        int ans=0;
        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};
        while(!q.empty()&&fresh>0){
            int k=q.size();
            for(int i=0;i<k;i++){
                auto [a,b]=q.front();
                q.pop();
                for(int d = 0; d < 4; d++){
                    int ni = a + dx[d];
                    int nj = b + dy[d];
                    if(ni>=0&&nj>=0&&ni<n&&nj<m){
                        if(grid[ni][nj]==1&&!vis[ni][nj]){
                            vis[ni][nj]=true;
                            fresh--;
                            grid[ni][nj]=2;
                            q.push({ni,nj});
                        }
                    }
                }
            }
            ans++;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) return -1;
            }
        }
        return ans;
    }
};