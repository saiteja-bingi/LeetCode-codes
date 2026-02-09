// Last updated: 09/02/2026, 21:05:14
class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& target) {
        int n=nums.size();
        int c=0;
        // if(nums[0]!=target[0]) c++;
        map<int,int>mp;
        for(int i=0;i<n;i++){
            // if(nums[i]!=nums[i-1]&&target[i]!=nums[i]) c++;
            if(nums[i]!=target[i]) mp[nums[i]]++;
        }
        c=mp.size();
        return c;
    }
};