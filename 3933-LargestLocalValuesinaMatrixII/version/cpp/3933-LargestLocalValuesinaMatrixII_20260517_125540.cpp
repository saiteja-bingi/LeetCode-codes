// Last updated: 17/5/2026, 12:55:40 pm
1class Solution {
2public:
3
4    bool valid(auto&matrix, auto& pre,int i,int j,int val){
5        int n=pre.size()-1;
6        int m=pre[0].size()-1;
7        int r1=max(0,i-val);
8        int r2=min(n-1,i+val);
9        int c1=max(0,j-val);
10        int c2=min(m-1,j+val);
11        int count=pre[r2+1][c2+1]-pre[r1][c2+1]-pre[r2+1][c1]+pre[r1][c1];
12        int dx[4]={-val,-val,val,val};
13        int dy[4]={val,-val,val,-val};
14        for(int k=0;k<4;k++){
15            int ni=i+dx[k];
16            int nj=j+dy[k];
17            if(ni>=0&&nj>=0&&ni<n&&nj<m&&matrix[ni][nj]>val) count--;
18        }
19        return count==0;
20    }
21    int countLocalMaximums(vector<vector<int>>& matrix) {
22        int n=matrix.size();
23        int m=matrix[0].size();
24        vector<vector<vector<int>>>pre(201,vector<vector<int>>(n+1,vector<int>(m+1,0)));
25        for(int k=0;k<201;k++){
26            for(int i=0;i<n;i++){
27                int c=0;
28                for(int j=0;j<m;j++){
29                    if(matrix[i][j]>k) c++;
30                    pre[k][i+1][j+1]=c+pre[k][i][j+1];
31                }
32            }
33        }
34        int ans=0;
35        for(int i=0;i<n;i++){
36            for(int j=0;j<m;j++){
37                int val=matrix[i][j];
38                if(val==0) continue;
39                if(valid(matrix,pre[val],i,j,val)) ans++;
40            }
41        }
42        return ans;
43    }
44};