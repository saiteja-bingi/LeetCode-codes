// Last updated: 15/04/2026, 00:44:22
class Solution {
public:

    long long findtotal(long long mid,vector<int>&arr){
        long long total=0;
        for(auto it:arr){
            long long k=(-1+sqrt(1+8*mid/it))/2;
            total+=k;
        }
        return total;
    }
    long long minNumberOfSeconds(int h, vector<int>& arr) {
        long long ans=0;
        long long i=0;
        long long j = 1e18;
        while(i<=j){
            long long mid=(i+j)/2;
            if(findtotal(mid,arr)>=h){
                ans=mid;
                j=mid-1;
            }
            else{
                i=mid+1;
            }
        }
        return ans;
    }
};