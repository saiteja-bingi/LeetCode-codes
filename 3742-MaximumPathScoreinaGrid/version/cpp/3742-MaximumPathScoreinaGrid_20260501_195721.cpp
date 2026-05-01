// Last updated: 1/5/2026, 7:57:21 pm
1class Solution {
2public:
3    int find(vector<vector<int>>&arr,int i,int j,int rc,vector<vector<vector<int>>>&dp){
4        int n=arr.size();
5        int m=arr[0].size();
6        if(i>=n||j>=m) return INT_MIN;
7        int cs=arr[i][j];
8        int cc=((arr[i][j]==0)?0:1);
9        if(cc>rc) return INT_MIN;
10        if(i==n-1&&j==m-1) return arr[i][j];
11        int nrc=rc-cc;
12        if(dp[i][j][nrc]!=-1) return dp[i][j][nrc];
13        int r=find(arr,i,j+1,nrc,dp);
14        int d=find(arr,i+1,j,nrc,dp);
15        int best=0;
16        best=max(r,d);
17        if(best<0) return dp[i][j][nrc]=INT_MIN;
18        return dp[i][j][nrc]= best+cs;
19    }
20    int maxPathScore(vector<vector<int>>& arr, int k) {
21        int n=arr.size();
22        int m=arr[0].size();
23        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(k+1,-1)));
24        int ans=find(arr,0,0,k,dp);
25        if(ans<0) return -1;
26        return ans;
27    }
28};