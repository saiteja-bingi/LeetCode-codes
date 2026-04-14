// Last updated: 15/04/2026, 00:44:16
class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<long long>suf(n,0);
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<m;j++){
                suf[i]+=grid[i][j];
            }
            suf[i]+=(i+1<n)?suf[i+1]:0;
        }
        long long sum=0;
        for(int i=0;i<n-1;i++){
            for(int j=0;j<m;j++) sum+=grid[i][j];
            if(sum==suf[i+1]) return true;
        }
        vector<long long>csuf(m,0);
        for(int j=m-1;j>=0;j--){
            for(int i=0;i<n;i++) csuf[j]+=grid[i][j];
            csuf[j]+=(j+1<m)?csuf[j+1]:0;
        }
        sum=0;
        for(int j=0;j<m-1;j++){
            for(int i=0;i<n;i++) sum+=grid[i][j];
            if(sum==csuf[j+1]) return true;
        }
        return false;
    }
};