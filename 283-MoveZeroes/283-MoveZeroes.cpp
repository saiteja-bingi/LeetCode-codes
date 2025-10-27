// Last updated: 10/27/2025, 7:20:48 PM
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int j=-1,i;
        for(i=0;i<nums.size();i++){
            if(nums[i]==0){
                j=i;
                break;
            }
        }
        if(j==-1){
            return;
        }
        for(i=j+1;i<nums.size();i++){
            if(nums[i]!=0){
                swap(nums[i],nums[j]);
                j++;
            }
        }
        
    }
};