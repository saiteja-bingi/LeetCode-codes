// Last updated: 10/27/2025, 7:08:59 PM
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int freq=0,i,ans;
        for(i=0;i<n;i++){
            if(freq==0){
                ans=nums[i];
            }
            if(nums[i]==ans){

                freq++;
            }
            else{
                freq--;
            }
        }
        //for variation problem
        int count=0;
        for(int val:nums){
            if(val==ans){
                count++;
            }
        }
        if(count>n/2){
        return ans;
        }
        return -1;
    }
};