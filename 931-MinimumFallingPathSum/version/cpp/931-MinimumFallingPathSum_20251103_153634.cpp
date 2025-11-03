// Last updated: 11/3/2025, 3:36:34 PM
class Solution {
public:

    int solve(vector<vector<int>>&arr,int n,int j,vector<vector<int>>&dp){
        if(n==0) return arr[n][j];

        if(dp[n][j]!=INT_MAX) return dp[n][j];
        
        int p1=INT_MAX,p2=INT_MAX,p3=INT_MAX;

        p1=arr[n][j]+solve(arr,n-1,j,dp);
        if(j+1<arr.size()) p2=arr[n][j]+solve(arr,n-1,j+1,dp);
        if(j-1>=0) p3=arr[n][j]+solve(arr,n-1,j-1,dp);

        int ans=min({p1,p2,p3});
        
        return dp[n][j]=ans;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>>dp(n,vector<int>(n,INT_MAX));
        int ans=INT_MAX;
        for(int j=0;j<n;j++){
            ans=min(ans,solve(matrix,n-1,j,dp));
        }
        return ans;
    }
};