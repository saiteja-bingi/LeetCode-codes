// Last updated: 10/27/2025, 7:08:09 PM
class Solution {
public:
    void function(vector<vector<int>>&ans,vector<int>&temp, int k,int n,vector<int>&nums,int index){
        if(temp.size()==k){
            if(n==0){
                ans.push_back(temp);
            }
        }
        if (temp.size() >= k || n <= 0) {
            return;
        }
        for(int i=index;i<nums.size();i++){
            temp.push_back(nums[i]);
            function(ans,temp,k,n-nums[i],nums,i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>temp;
        vector<int>num{1,2,3,4,5,6,7,8,9};
        function(ans,temp,k,n,num,0);
        return ans;
    }
};