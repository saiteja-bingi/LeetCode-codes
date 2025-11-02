// Last updated: 11/2/2025, 8:05:23 AM
class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int>ans;
        set<int>st;
        for(auto it:nums){
            st.insert(it);
        }
        int mi=*min_element(nums.begin(),nums.end());
        int ma=*max_element(nums.begin(),nums.end());
        mi++;
        while(mi<ma){
            if(!st.count(mi)){
                ans.push_back(mi);
            }
            mi++;
        }
        return ans;
    }
};