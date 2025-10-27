// Last updated: 10/27/2025, 7:10:13 PM
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();
        int low=0,high=n-1,mid,ans=n;
        while(low<=high){
            mid=(low+high)/2;
            if(nums[mid]>=target){
                ans=min(ans,mid);
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        } 
        return ans;
    }
};