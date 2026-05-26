// Last updated: 26/5/2026, 10:10:03 pm
1class Solution {
2public:
3    vector<int> limitOccurrences(vector<int>& nums, int k) {
4        unordered_map<int,int>mp;
5        vector<int>ans;
6        for(int i=0;i<nums.size();i++){
7            mp[nums[i]]++;
8            if(mp[nums[i]]<=k) ans.push_back(nums[i]);
9        }
10        return ans;
11    }
12};