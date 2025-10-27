// Last updated: 10/27/2025, 7:07:45 PM
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int i,x1=0,x2=0;
        int n=nums.size();
        for(i=0;i<=n;i++){
            x1=x1^i;
        }
        for(i=0;i<n;i++){
            x2=x2^nums[i];
        }
        return x1^x2;
            }
};