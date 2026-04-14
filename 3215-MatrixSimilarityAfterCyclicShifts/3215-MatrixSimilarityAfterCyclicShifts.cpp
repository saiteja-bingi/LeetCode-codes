// Last updated: 15/04/2026, 00:44:32
class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n=mat.size();
        int m=mat[0].size();
        k%=m;
        for(int i=0;i<n;i++){
            int nsf=k;
            if(i%2!=0) nsf=m-k;
            int x=nsf;
            cout<<x<<endl;
            for(int t=0;t<m;t++){
                if(mat[i][t]!=mat[i][(t+x)%m]) return false;
            }
        }
        return true;
    }
};