// Last updated: 15/04/2026, 00:45:04
class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>pre(n,vector<int>(m));
        for(int j=0;j<m;j++){
            for(int i=0;i<n;i++){
                if(mat[i][j]==0) pre[i][j]=0;
                else pre[i][j]=(i-1>=0)?pre[i-1][j]+1:1;
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            sort(pre[i].begin(),pre[i].end(),greater<int>());
            int s=0;
            for(int j=0;j<m;j++){
                // mi=min(mi,pre[i][j]);
                s=max(s,pre[i][j]*(j+1));
            }
            ans=max(ans,s);
        }
        return ans;
    }
};