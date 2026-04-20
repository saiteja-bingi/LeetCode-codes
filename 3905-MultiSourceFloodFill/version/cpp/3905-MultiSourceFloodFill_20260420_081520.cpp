// Last updated: 20/4/2026, 8:15:20 am
1class Solution {
2public:
3    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
4        vector<vector<int>>ans(n,vector<int>(m,0));
5        vector<vector<int>>dist(n,vector<int>(m,1e9));
6        queue<array<int,4>>q;
7        for(auto& it:sources){
8            int r=it[0],c=it[1],col=it[2];
9            ans[r][c]=max(ans[r][c],col);
10            dist[r][c]=0;
11            q.push({r,c,col,0});
12        }
13        int dx[4]={0,0,1,-1};
14        int dy[4]={1,-1,0,0};
15        while(!q.empty()){
16            int sz=q.size();
17            for(int i=0;i<sz;i++){
18                auto [r,c,col,d]=q.front();
19                q.pop();
20                for(int k=0;k<4;k++){
21                    int nx=r+dx[k],ny=c+dy[k];
22                    if(nx<0||ny<0||nx>=n||ny>=m) continue;
23                    if(d+1==dist[nx][ny]){
24                        if(col>ans[nx][ny]){
25                            ans[nx][ny]=col;
26                            q.push({nx,ny,col,d+1});
27                        }
28                    }
29                    else if(d+1<dist[nx][ny]){
30                        dist[nx][ny]=d+1;
31                        ans[nx][ny]=col;
32                        q.push({nx,ny,col,d+1});
33                    }
34                }
35            }
36        }
37        return ans;
38        
39    }
40};