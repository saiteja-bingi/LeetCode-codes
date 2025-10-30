// Last updated: 10/30/2025, 9:38:18 PM
class Solution {
public:
    int minNumberOperations(vector<int>& arr) {
        int n=arr.size();
        int count=arr[0];
        for(int i=1;i<n;i++){
            if(arr[i]>=arr[i-1]){
                count+=arr[i]-arr[i-1];
            }
        }
        return count;
    }
};