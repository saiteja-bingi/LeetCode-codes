// Last updated: 20/4/2026, 7:42:23 am
#define ll long long

class Solution {
public:
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        vector<vector<int>>grid(n,vector<int>(m,0));
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<array<int,3>>q;
        for(auto it:sources){
            grid[it[0]][it[1]]=max(grid[it[0]][it[1]],it[2]);
        }
        for(auto it:sources){
            int x=it[0],y=it[1];
            if(!vis[x][y]){
                vis[x][y]=1;
                q.push({x,y,grid[x][y]});
            }
        }
        int dx[4]={0,0,1,-1};
        int dy[4]={1,-1,0,0};
        while(!q.empty()){
            int sz=q.size();
            unordered_map<ll,ll>mp;
            for(int i=0;i<sz;i++){
                auto it=q.front();
                q.pop();
                int x=it[0],y=it[1],col=it[2];
                
                for(int k=0;k<4;k++){
                    int nx=x+dx[k],ny=y+dy[k];
                    if(nx<0||nx>=n||ny<0||ny>=m) continue;
                    if(vis[nx][ny]) continue;
                    ll ky=1ll*nx*m+ny;
                    mp[ky]=max(mp[ky],1ll*col);
                }

            }
            for(auto it:mp){
                int x=it.first/m,y=it.first%m,col=it.second;
                vis[x][y]=1;
                grid[x][y]=col;
                q.push({x,y,col});
            }
        }
        return grid;
    }
};