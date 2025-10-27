// Last updated: 10/27/2025, 7:09:00 PM
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int low=0,high=n-1,mid;
        int ans=INT_MAX;
        while(low<=high){
            mid=(low+high)/2;
            ans=min(nums[mid],ans);
            if(nums[low]<=nums[mid]){
                ans=min(nums[low],ans);
                low=mid+1;
            }
            else{
                ans=min(nums[mid+1],ans);
                high=mid-1;
            }
        }
        return ans;
    }
};