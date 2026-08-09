// Last updated: 09/08/2026, 08:31:32
1class Solution {
2public:
3    int maxArea(vector<vector<int>>& mat) {
4        int m=mat.size(),n=mat[0].size();
5        vector<vector<int>>p(m+1,vector<int>(n+1,0));
6        for(int i=0;i<m;i++){
7            for(int j=0;j<n;j++){
8                p[i+1][j+1]=mat[i][j]+p[i][j+1]+p[i+1][j]-p[i][j];
9            }
10        }
11        auto ok=[&](int r,int c,int k){
12            int r2=r+k,c2=c+k;
13            int s=p[r2][c2]-p[r][c2]-p[r2][c]+p[r][c];
14            return s==k*k;
15        };
16        for(int k=min(m,n);k>=1;k--){
17            int a=INT_MAX,b=INT_MIN;
18            int c1=a,d=b,cnt=0;
19            for(int r=0;r+k<=m;r++){
20                for(int c=0;c+k<=n;c++){
21                    if(ok(r,c,k)){
22                        cnt++;
23                        a=min(a,r);b=max(b,r);
24                        c1=min(c1,c);d=max(d,c);
25                    }
26                }
27            }
28            if(cnt>=2&&(d-c1>=k||b-a>=k)) return k*k;
29        }
30        return 0;
31    }
32};