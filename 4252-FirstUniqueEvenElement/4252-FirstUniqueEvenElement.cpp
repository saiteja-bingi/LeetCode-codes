// Last updated: 08/04/2026, 23:54:39
class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        int ans=-1;
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            if(!(nums[i]&1)) mp[nums[i]]++;
        }
        for(int i=0;i<nums.size();i++){
            if(mp[nums[i]]==1) return  nums[i];
        }
        return ans;
    }
};