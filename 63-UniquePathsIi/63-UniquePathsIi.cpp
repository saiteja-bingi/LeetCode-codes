// Last updated: 10/27/2025, 7:09:45 PM
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        // vector<vector<int>>dp(n,vector<int>(m,0));
        vector<int>dp(n,0);
        for(int i=0;i<n;i++){
            vector<int>temp(m,0);
            for(int j=0;j<m;j++){
                if(grid[i][j]){
                    temp[j]=0;
                }
                else if(i==0&&j==0){
                    temp[0]=1;
                }
                else{
                    int left=0,up=0;
                    if(i>0) up=dp[j];
                    if(j>0) left=temp[j-1];
                    temp[j]=left+up;
                }
            }
            dp=temp;
        }
        return dp[m-1];
    }
};