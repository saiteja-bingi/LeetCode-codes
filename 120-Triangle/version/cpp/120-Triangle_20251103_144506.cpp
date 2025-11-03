// Last updated: 11/3/2025, 2:45:06 PM
class Solution {
public:
    int solve(vector<vector<int>>&arr,int i,int j,int n,vector<vector<int>>&dp){
        if(i==n-1){
            return arr[i][j];
        }
        if(dp[i][j]!=INT_MAX) return dp[i][j];
        int p1=arr[i][j]+solve(arr,i+1,j,n,dp);
        int p2=arr[i][j]+solve(arr,i+1,j+1,n,dp);
        return dp[i][j]=min(p1,p2);
        
    }
    int minimumTotal(vector<vector<int>>& a) {
        int n=a.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int j=0;j<n;j++){
            dp[n-1][j]=a[n-1][j];
        }
        for(int i=n-2;i>=0;i--){
            for(int k=i;k>=0;k--){
                int p1=a[i][k]+dp[i+1][k];
                int p2=a[i][k]+dp[i+1][k+1];
                dp[i][k]=min(p1,p2);
            }
        }
        return dp[0][0];
    }
};