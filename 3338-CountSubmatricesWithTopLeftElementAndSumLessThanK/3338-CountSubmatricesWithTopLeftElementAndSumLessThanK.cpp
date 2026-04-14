// Last updated: 15/04/2026, 00:44:30
class Solution {
public:
    int countSubmatrices(vector<vector<int>>& arr, int k) {
        int n=arr.size();
        int m=arr[0].size();
        int ans=1;
        vector<int>prev(m,0);
        prev[0]=arr[0][0];
        if(prev[0]>k) return 0;
        for(int i=1;i<m;i++){
            prev[i]=prev[i-1]+arr[0][i];
            if(prev[i]<=k) ans++;
        }
        for(int i=1;i<n;i++){
            int cur=0;
            for(int j=0;j<m;j++){
                cur+=arr[i][j];
                if(prev[j]+cur<=k) ans++;
                prev[j]=prev[j]+cur; 
            }
        }
        return ans;
    }
};