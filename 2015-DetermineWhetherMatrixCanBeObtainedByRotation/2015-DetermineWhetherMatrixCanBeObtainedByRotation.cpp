// Last updated: 15/04/2026, 00:44:56
class Solution {
public:
    void rotate(auto& mat){
        int n=mat.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                swap(mat[i][j],mat[j][i]);
            }
        }
        for(auto &it:mat){
            reverse(it.begin(),it.end());
        }
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int i=4;
        while(i--){
            if(mat==target) return true;
            rotate(mat);
        }
        return false;
    }
};