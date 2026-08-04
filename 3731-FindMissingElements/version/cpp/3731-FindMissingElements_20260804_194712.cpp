// Last updated: 4/8/2026, 7:47:12 pm
1class Solution {
2public:
3    vector<int> findMissingElements(vector<int>& nums) {
4        sort(nums.begin(),nums.end());
5        vector<int>ans;
6        int ele=nums[0];
7        for(int i=0;i<nums.size();i++){
8            if(nums[i]==ele) {ele++;continue;}
9            while(ele<nums[i]) {ans.push_back(ele);ele++;}
10            ele++;
11        }
12        return ans;
13    }
14};