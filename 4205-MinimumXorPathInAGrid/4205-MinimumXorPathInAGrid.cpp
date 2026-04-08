// Last updated: 08/04/2026, 23:55:06
class Solution {
public:
    /*
        (0,0)->(n-1,m-1);
        go rigth ot down
        dp[i][j]=dp[i-1][j],dp[i][j-1]

    */

    int minCost(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<bool>>>dp(n,vector<vector<bool>>(m,vector<bool>(1024,0)));
        dp[0][0][grid[0][0]]=1;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0&&j==0) continue;
                for(int x=0;x<1024;x++){
                    int k=0;
                    if(i>0&&dp[i-1][j][x^grid[i][j]]) k=1;
                    if(j>0&&dp[i][j-1][x^grid[i][j]]) k=1;
                    dp[i][j][x]=k;
                }
            }
        }
        for(int x=0;x<1024;x++){
            if(dp[n-1][m-1][x]) return x;
        }
        return 0;
    }
};