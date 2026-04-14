// Last updated: 15/04/2026, 00:44:57
class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& arr) {
        set<int>st;
        int n=arr.size(),m=arr[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                st.insert(arr[i][j]);
                int k=1;
                while(1){
                    if(i+2*k>=n||j-k<0||j+k>=m) break;
                    int sum=0;
                    int r,c;
                    r=i;c=j;
                    for(int it=0;it<k;it++) sum+=arr[r+it][c-it];
                    r=i+k;c=j-k;
                    for(int it=0;it<k;it++) sum+=arr[r+it][c+it];
                    r=i;c=j;
                    for(int it=1;it<=k;it++) sum+=arr[r+it][c+it];
                    r=i+k;c=j+k;
                    for(int it=1;it<=k;it++) sum+=arr[r+it][c-it];
                    st.insert(sum);
                    k++;
                }
            }
        }
        vector<int>ans;
        auto it=st.rbegin();
        for(int i=0;i<3&&it!=st.rend();i++,it++){
            ans.push_back(*it);
        }
        return ans;
    }
};