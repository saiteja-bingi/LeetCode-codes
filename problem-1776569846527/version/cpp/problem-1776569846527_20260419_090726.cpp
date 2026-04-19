// Last updated: 19/4/2026, 9:07:26 am
1#define ll long long
2
3class Solution {
4public:
5    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
6        vector<vector<int>>grid(n,vector<int>(m,0));
7        vector<vector<int>>vis(n,vector<int>(m,0));
8        queue<array<int,3>>q;
9        for(auto it:sources){
10            grid[it[0]][it[1]]=max(grid[it[0]][it[1]],it[2]);
11        }
12        for(auto it:sources){
13            int x=it[0],y=it[1];
14            if(!vis[x][y]){
15                vis[x][y]=1;
16                q.push({x,y,grid[x][y]});
17            }
18        }
19        int dx[4]={0,0,1,-1};
20        int dy[4]={1,-1,0,0};
21        while(!q.empty()){
22            int sz=q.size();
23            unordered_map<ll,ll>mp;
24            for(int i=0;i<sz;i++){
25                auto it=q.front();
26                q.pop();
27                int x=it[0],y=it[1],col=it[2];
28                
29                for(int k=0;k<4;k++){
30                    int nx=x+dx[k],ny=y+dy[k];
31                    if(nx<0||nx>=n||ny<0||ny>=m) continue;
32                    if(vis[nx][ny]) continue;
33                    ll ky=1ll*nx*m+ny;
34                    mp[ky]=max(mp[ky],1ll*col);
35                }
36
37            }
38            for(auto it:mp){
39                int x=it.first/m,y=it.first%m,col=it.second;
40                vis[x][y]=1;
41                grid[x][y]=col;
42                q.push({x,y,col});
43            }
44        }
45        return grid;
46    }
47};