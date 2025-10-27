// Last updated: 10/27/2025, 7:05:00 PM
class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int rr=x+k,cr=y+k;
        int i=x;
        int l=rr-1;
        while(i<=l&&i<rr&&l>=0){
            for(int j=y;j<cr;j++){
                swap(grid[i][j],grid[l][j]);
            }
            i++;
            l--;
        }
        return grid;
    }
};