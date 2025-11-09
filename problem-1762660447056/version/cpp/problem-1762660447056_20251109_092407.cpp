// Last updated: 11/9/2025, 9:24:07 AM
class Solution {
public:
    int find(vector<vector<int>>&arr,int i,int j,int rc,vector<vector<vector<int>>>&dp){
        int n=arr.size();
        int m=arr[0].size();
        if(i>=n||j>=m) return INT_MIN;
        int cs=arr[i][j];
        int cc=((arr[i][j]==0)?0:1);
        if(cc>rc) return INT_MIN;
        if(i==n-1&&j==m-1) return arr[i][j];
        int nrc=rc-cc;
        if(dp[i][j][nrc]!=-1) return dp[i][j][nrc];
        int r=find(arr,i,j+1,nrc,dp);
        int d=find(arr,i+1,j,nrc,dp);
        int best=0;
        best=max(r,d);
        if(best<0) return dp[i][j][nrc]=INT_MIN;
        return dp[i][j][nrc]= best+cs;
    }
    int maxPathScore(vector<vector<int>>& arr, int k) {
        int n=arr.size();
        int m=arr[0].size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(k+1,-1)));
        int ans=find(arr,0,0,k,dp);
        if(ans<0) return -1;
        return ans;
    }
};