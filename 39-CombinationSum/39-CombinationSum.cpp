// Last updated: 10/27/2025, 7:10:07 PM
class Solution {
public:

    void function(vector<int>arr,vector<vector<int>>&vec,pair<vector<int>,int>&temp,int target,int i){
        if(i==arr.size()){
            if(temp.second==target){
                vec.push_back(temp.first);
            }
            return;
        }
        if(temp.second<=target){
        temp.second+=arr[i];
        temp.first.push_back(arr[i]);
        function(arr,vec,temp,target,i);
        temp.second-=arr[i];
        temp.first.pop_back();
        }
        function(arr,vec,temp,target,i+1);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>vec;
        pair<vector<int>,int>temp;
        temp.second=0;
        function(candidates,vec,temp,target,0);
        return vec;
    }
};