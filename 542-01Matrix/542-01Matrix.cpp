// Last updated: 15/04/2026, 00:46:26
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>dist(n,vector<int>(m,-1));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                    dist[i][j]=0;
                }
            }
        }
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,1,-1};
        while(!q.empty()){
            auto [x,y]=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int ni=x+dx[i];
                int nj=y+dy[i];
                if(ni>=0&&ni<n&&nj>=0&&nj<m&&dist[ni][nj]==-1){
                    dist[ni][nj]=dist[x][y]+1;
                    q.push({ni,nj});
                }
            }
        }
        return dist;

    }
};