// Last updated: 09/02/2026, 21:08:20
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
        vector<int>dp(n,0);
        for(int j=0;j<n;j++){
            dp[j]=a[n-1][j];
        }
        for(int i=n-2;i>=0;i--){
            vector<int>temp(n,0);
            for(int k=i;k>=0;k--){
                int p1=a[i][k]+dp[k];
                int p2=a[i][k]+dp[k+1];
                temp[k]=min(p1,p2);
            }
            dp=temp;
        }
        return dp[0];
    }
};