// Last updated: 1/11/2026, 11:10:07 AM
class Solution {
public:
    vector<string> pal;

    void gen(string &s, int l, int r) {
        if (l > r) {
            pal.push_back(s);
            return;
        }
        if (l != 0) {
        s[l] = s[r] = '0';
        gen(s, l + 1, r - 1);
    }
        s[l] = s[r] = '1';
        gen(s, l + 1, r - 1);
    }

    vector<int> minOperations(vector<int>& nums) {
        int n=nums.size();
        vector<int>vec;
        for(int i=0;i<n;i++){
            string s = bitset<32>(nums[i]).to_string();
            s = s.substr(s.find('1'));
            string k(s.size(),'0');
            gen(k,0,s.size()-1);
            int d=INT_MAX;
            for(auto it:pal){
                long long num = bitset<64>(it).to_ullong();
                int r=abs(num-nums[i]);
                d=min(r,d);
            }
            vec.push_back(d);
            pal.clear();
        }
        return vec;
    }
};