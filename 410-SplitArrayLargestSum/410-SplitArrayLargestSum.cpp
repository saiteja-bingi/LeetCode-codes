// Last updated: 10/27/2025, 7:07:12 PM
class Solution {
public:
    long long findmax(vector<int>&arr){
        int large=arr[0];
        for(auto it:arr){
            large=max(large,it);
        }
        return large;
    }

bool ispossible(vector<int>&arr,long long mid,int k){
    long long count=1,sum=0;
    for(auto it:arr){
        if(sum+it<=mid){
            sum+=it;
        }
        else{
            sum=it;
            count++;
        }
    }
    if(count<=k) return true;
    return false;
}

    int splitArray(vector<int>& nums, int k) {
        long long low=findmax(nums),high=accumulate(nums.begin(),nums.end(),0);
        long long mid=low,ans=low;
        while(low<=high){
            mid=(low+high)/2;
            if(ispossible(nums,mid,k)){
                high=mid-1;
                ans=mid;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};