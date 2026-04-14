// Last updated: 15/04/2026, 00:42:28
class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<int>ans(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++) ans[j]+=matrix[i][j];
        }
        return ans;
    }
};