// Last updated: 19/8/2026, 11:58:36 pm
class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        vector<int>ans;
        int l1=-1,l2=nums[0];
        int c=0;
        for(int i=0;i<nums.size();i++){
            l2=nums[i];
            if(l1!=l2) c=0;
            c++;
            if(c<=k) ans.push_back(nums[i]);
            l1=l2;
        }
        return ans;
    }
};