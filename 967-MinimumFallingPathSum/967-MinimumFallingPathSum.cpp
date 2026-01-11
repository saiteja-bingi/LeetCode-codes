// Last updated: 1/11/2026, 10:03:35 PM
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& arr) {
        int n=arr.size();
        int ans=INT_MAX;
        vector<int>dp(n,0);
        for(int j=0;j<n;j++){
            dp[j]=arr[0][j];
        }
        for(int i=1;i<n;i++){
            vector<int>temp(n,0);
            for(int j=0;j<n;j++){
                int p1=INT_MAX,p2=INT_MAX,p3=INT_MAX;
                p1=arr[i][j]+dp[j];
                if(j+1<n) p2=arr[i][j]+dp[j+1];
                if(j-1>=0) p3=arr[i][j]+dp[j-1];
                temp[j]=min({p1,p2,p3});
            }
            dp=temp;
        }
        for(int j=0;j<n;j++){
            ans=min(ans,dp[j]);
        }
        return ans;
    }
};