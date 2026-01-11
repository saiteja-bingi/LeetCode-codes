// Last updated: 1/11/2026, 11:10:00 AM
class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp(n);
        
        for(int i = 0; i < n; i++) {
            int m = nums[i];
            string st = to_string(m);
            reverse(st.begin(), st.end());
            m = stoi(st);
            temp[i] = m;
        }
        
        map<int, set<int>> mp;
        for(int i = 0; i < n; i++) {
            mp[temp[i]].insert(i);
        }
        
        int len = INT_MAX;
        for(int i = 0; i < n; i++) {
            auto &st = mp[nums[i]];
            if(st.empty()) continue;

            auto it = st.lower_bound(i);
            if (it != st.begin()) {
                --it;                    
                len = min(len, abs(*it - i));
            }
        }
        return len == INT_MAX ? -1 : len;
    }
};
