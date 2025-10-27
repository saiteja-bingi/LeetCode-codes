// Last updated: 10/27/2025, 7:05:06 PM
class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {
        long long t_sum=0;
        sort(nums.begin(),nums.end());
        int i=0,j=nums.size()-1;
        while(i<=j){
            t_sum+=nums[j-1];
            j-=2;
            i+=1;
        }
        return t_sum;
    }
};