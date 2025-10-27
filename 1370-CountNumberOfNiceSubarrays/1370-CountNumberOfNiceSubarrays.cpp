// Last updated: 10/27/2025, 7:06:25 PM
class Solution {
public:
    int findAtmost(vector<int>&nums,int k){
        if(k<0) return 0;
        int n=nums.size();
        int odd=0,l=0,r=0,count=0;
        while(r<n){
            if(nums[r]%2!=0) odd++;
            while(odd>k){
                if(nums[l]%2!=0) odd--;
                l++;
            }
            count+=-r-l+1;
            r++;
        }
        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return findAtmost(nums,k)-findAtmost(nums,k-1);
    }
};