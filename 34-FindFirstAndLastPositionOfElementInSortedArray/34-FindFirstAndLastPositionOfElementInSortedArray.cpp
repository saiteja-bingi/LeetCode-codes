// Last updated: 10/27/2025, 7:10:17 PM
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int low=0,high=n-1,mid,flr=-1,cel=-1;
        while(low<=high){
            mid=(low+high)/2;
            if(nums[mid]==target){
                flr=mid;
                high=mid-1;
            }
            else if(nums[mid]<target){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        low=0;
        high=n-1;
        while(low<=high){
            mid=(low+high)/2;
            if(nums[mid]==target){
                cel=mid;
                low=mid+1;
            }
            else if(nums[mid]>target){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return {flr,cel} ;
    }
};