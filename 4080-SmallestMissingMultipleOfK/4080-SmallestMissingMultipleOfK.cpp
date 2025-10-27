// Last updated: 10/27/2025, 7:04:33 PM
class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        set<int>st;
        for(auto it:nums){
            if(it%k==0) st.insert(it);
        }
        int c1=1;
        for(auto it:st){
            if(k*c1!=it) return k*c1;
            c1++;
        }
        return k*c1;
    }
};