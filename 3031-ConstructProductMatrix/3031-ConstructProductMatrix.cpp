// Last updated: 15/04/2026, 00:44:33
class Solution {
public:
    const int mod=12345;
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        if(n==1&&m==1) return {{0}};
        __int128 p=1;
        vector<vector<int>>ans(n,vector<int>(m,1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans[i][j]=(ans[i][j]*p)%mod;
                p=(p*grid[i][j])%mod;
            }
        }
        __int128 s=1;
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                ans[i][j]=(ans[i][j]*s)%mod;
                s=(s*grid[i][j])%mod;
            }
        }
        return ans;
    }
};