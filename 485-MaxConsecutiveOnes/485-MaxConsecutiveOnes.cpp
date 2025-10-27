// Last updated: 10/27/2025, 7:07:01 PM
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int m=0,n=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                m++;
                n=max(n,m);
            }
            else{
                m=0;
            }
        }
        
        return n;
    }
};