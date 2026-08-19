// Last updated: 19/8/2026, 11:58:55 pm
class Solution {
public:
    vector<int> countOppositeParity(vector<int>& arr) {
        int n=arr.size();
        vector<int>ans(n,0);
        for(int  i=0;i<n;i++){
            int c=0;
            for(int j=i+1;j<n;j++){
                if(i!=j&&(arr[i]+arr[j])&1) c++;
            }
            ans[i]=c;
        }
        return ans;
    }
};