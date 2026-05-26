// Last updated: 26/5/2026, 10:12:14 pm
1class Solution {
2public:
3    vector<int> limitOccurrences(vector<int>& nums, int k) {
4        vector<int>ans;
5        int l1=-1,l2=nums[0];
6        int c=0;
7        for(int i=0;i<nums.size();i++){
8            l2=nums[i];
9            if(l1!=l2) c=0;
10            c++;
11            if(c<=k) ans.push_back(nums[i]);
12            l1=l2;
13        }
14        return ans;
15    }
16};