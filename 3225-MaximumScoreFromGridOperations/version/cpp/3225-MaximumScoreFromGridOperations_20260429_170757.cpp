// Last updated: 29/4/2026, 5:07:57 pm
1class Solution {
2public:
3    long long dp[102][101][2];
4    long long f(int i,int j,int fl,vector<vector<int>> &grid,int m) {
5        if(m==1 || j>=m) return 0;
6        if(dp[i+1][j][fl]!=-1) return dp[i+1][j][fl];
7        long long ans = f(grid.size()-1,j+1,0,grid,m);;
8        long long sum = 0;
9        if(j==0) {
10            for(int ind=0;ind<grid.size();ind++) {
11                sum += grid[ind][j];
12                ans = max(ans,sum+f(ind,j+1,1,grid,m));
13            }
14        }
15        else if(j<m-1) {
16            if(fl==0) {
17                for(int ind=i;ind>=0;ind--) {
18                    sum += grid[ind][j];
19                    ans = max(ans,sum+f(ind-1,j+1,0,grid,m));
20                }
21                for(int ind = i+1;ind<grid.size();ind++) {
22                    sum += grid[ind][j];
23                    ans = max(ans,sum+f(ind,j+1,1,grid,m));
24                }
25            }
26            else {
27                for(int ind=i+1;ind<grid.size();ind++) {
28                    sum += grid[ind][j];
29                    ans = max(ans,sum+f(ind,j+1,1,grid,m));
30                }
31            }
32        }
33        else {
34            if(fl==0) for(int ind=0;ind<=i;ind++) ans += grid[ind][j];
35        }
36        return dp[i+1][j][fl] = ans;
37    }
38    long long maximumScore(vector<vector<int>>& grid) {
39        memset(dp,-1,sizeof(dp));
40        return f(-1,0,0,grid,grid[0].size());
41    }
42};