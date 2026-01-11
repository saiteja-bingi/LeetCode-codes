// Last updated: 1/11/2026, 11:10:26 AM
class Solution {
public:
    int findMaxVal(int n, vector<vector<int>>& res, vector<int>& diff) {
        vector<int>arr(n,INT_MAX);
        arr[0]=0;
        for(auto it:res){
            int idx=it[0];
            int val=it[1];
            arr[idx]=min(arr[idx],val);
        }
        for(int i=1;i<n;i++){
            arr[i]=min(arr[i],diff[i-1]+arr[i-1]);
        }
        for(int i=n-2;i>=0;i--){
            arr[i]=min(arr[i],arr[i+1]+diff[i]);
        }
        return *max_element(arr.begin(),arr.end());
    }
};