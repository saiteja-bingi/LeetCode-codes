// Last updated: 15/04/2026, 00:45:51
class Solution {
public:
    int dfs(vector<vector<int>>&grid,int i,int j){
        if(i<0||i>=grid.size()||j<0||j>=grid[0].size()||grid[i][j]==0) return 0;
        grid[i][j]=0;
        int ans=1+dfs(grid,i-1,j)+dfs(grid,i+1,j)+dfs(grid,i,j-1)+dfs(grid,i,j+1);
        return ans;
    }
    int maxAreaOfIsland(vector<vector<int>>& arr) {
        int n=arr.size();
        int m=arr[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(arr[i][j]==1) ans=max(ans,dfs(arr,i,j));
            }
        }
        return ans;
    }
};