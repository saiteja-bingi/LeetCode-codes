// Last updated: 10/27/2025, 7:08:49 PM
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        int low=1,high=n-2,mid;
        if(n==1) return 0;
        if(nums[0]>nums[1]) return 0;
        if(nums[n-1]>nums[n-2]) return n-1;

        while(low<=high){
            mid=(low+high)/2;
            if(nums[mid-1]<nums[mid]&&nums[mid]>nums[mid+1]){
                return mid;
            }
            if(nums[mid]<nums[mid+1]){
                low=mid+1;
            }
            else if(nums[mid-1]>nums[mid]){
                high=mid-1;
            }
        }
        return -1;
    }
};