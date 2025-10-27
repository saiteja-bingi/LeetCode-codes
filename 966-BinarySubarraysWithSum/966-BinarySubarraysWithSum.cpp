// Last updated: 10/27/2025, 7:06:32 PM
class Solution {
public:
    int FindAtmost(vector<int>&nums,int goal){
        if(goal<0) return 0;
        int l=0,r=0,n=nums.size();
        int sum=0;
        int count=0;
        while(r<n){
            sum+=nums[r];
            while(sum>goal){
                sum-=nums[l];
                l++;
            }
            count+=(r-l+1);
            r++;
        }
        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return FindAtmost(nums,goal)-FindAtmost(nums,goal-1);
    }
};