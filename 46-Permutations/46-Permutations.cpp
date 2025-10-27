// Last updated: 10/27/2025, 7:10:01 PM
class Solution {
public:
    void function(vector<int>&nums,vector<vector<int>>&ans,int index){
        if(index>=nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i=index;i<nums.size();i++){
            swap(nums[index],nums[i]);
            function(nums,ans,index+1);
            swap(nums[index],nums[i]);
            
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        function(nums,ans,0);
        return ans;
    }
};