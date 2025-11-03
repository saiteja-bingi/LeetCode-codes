// Last updated: 11/3/2025, 2:25:32 PM
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
    int minimumTotal(vector<vector<int>>& arr) {
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(n,INT_MAX));
        int ans=solve(arr,0,0,n,dp);
        return ans;
    }
};