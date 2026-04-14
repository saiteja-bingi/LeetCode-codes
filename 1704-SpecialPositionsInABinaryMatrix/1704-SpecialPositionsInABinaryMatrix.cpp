// Last updated: 15/04/2026, 00:45:12
class Solution {
public:
    int numSpecial(vector<vector<int>>& arr) {
        int n=arr.size();
        int m=arr[0].size();
        vector<int>rows(n);
        vector<int>cols(m);
        int ans=0;
        for(int i=0;i<n;i++){
            int c=0;
            for(int j=0;j<m;j++){
                if(arr[i][j]==1) c++;
            }
            rows[i]=c;
        }
        for(int j=0;j<m;j++){
            int c=0;
            for(int i=0;i<n;i++){
                if(arr[i][j]==1) c++;
            }
            cols[j]=c;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(arr[i][j]==1&&rows[i]-arr[i][j]==0&&cols[j]-arr[i][j]==0){
                    ans++;
                }
            }
        }
        return ans;
    }
};

/*
    0 0 1 0
    0 0 0 0 
    0 0 0 0 
    0 1 0 0
*/