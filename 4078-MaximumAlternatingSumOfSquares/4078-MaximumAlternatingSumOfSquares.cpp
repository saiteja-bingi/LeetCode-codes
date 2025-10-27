// Last updated: 10/27/2025, 7:04:41 PM
class Solution {
public:
    long long maxAlternatingSum(vector<int>& arr) {
        int n=arr.size();
        for(int i=0;i<n;i++){
            arr[i]=abs(arr[i]);
        }
        sort(arr.begin(),arr.end());
        long long sum=0;
        int mid=n/2;
        for(int i=0;i<n;i++){
            if(i<mid){
                sum-=arr[i]*arr[i];
            }
            else{
                sum+=arr[i]*arr[i];
            }
        }
        return sum;
    }
};