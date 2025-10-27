// Last updated: 10/27/2025, 7:06:30 PM
class Solution {
public:
    int findAtmost(vector<int>&nums,int k){
        if(k<=0) return 0;
        int n=nums.size();
        int l=0,r=0,count=0;
        unordered_map<int,int>mp;
        while(r<n){
            if(mp[nums[r]]==0) k--;
            mp[nums[r]]++;
            while(k<0){
                if(mp[nums[l]]==1) k++;
                mp[nums[l]]--;
                l++;
            }
            count+=r-l+1;
            r++;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return findAtmost(nums,k)-findAtmost(nums,k-1);
    }
};