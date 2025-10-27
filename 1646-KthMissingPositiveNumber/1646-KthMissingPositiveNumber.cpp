// Last updated: 10/27/2025, 7:06:15 PM
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        if(k<arr[0]) return k;
        int low=0,high=arr.size()-1,mid;
        while(low<=high){
            mid=(low+high)/2;
            int missing=arr[mid]-(mid+1);
            if(missing<k) low=mid+1;
            else high=mid-1;
        }
        return high+1+k;
    }
};