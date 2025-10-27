// Last updated: 10/27/2025, 7:06:23 PM
class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int ma=INT_MIN;
        // largest number
        for(auto it:nums){
            ma=max(ma,it);
        }
        int ans=ma;
        int low=1,high=ma,mid;
        while(low<=high){
            mid=(low+high)/2;
            long long sum=0;
            for(int j=0;j<nums.size();j++){
                sum+=ceil((double)nums[j]/mid);
            }
            if(sum<=threshold){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
            
        }
        return ans;
    }
};