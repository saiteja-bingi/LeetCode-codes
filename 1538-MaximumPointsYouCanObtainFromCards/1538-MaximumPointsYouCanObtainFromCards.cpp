// Last updated: 10/27/2025, 7:06:21 PM
class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int n=nums.size();
        int lsum=0;
        int rsum=0;
        int sum=0;
        int l=0;
        int r=n-1;
        while(l<k){
            lsum+=nums[l];
            l++;
        }
        l--;
        sum=lsum;
        while(l>=0){
            lsum-=nums[l];
            l--;
            rsum+=nums[r];
            r--;
            sum=max(sum,lsum+rsum);
        }
        return sum;
    }
};