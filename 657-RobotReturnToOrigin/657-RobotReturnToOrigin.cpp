// Last updated: 15/04/2026, 00:45:54
class Solution {
public:
    bool judgeCircle(string moves) {
        unordered_map<char,int>mp;
        for(auto it:moves) mp[it]++;
        if(mp['U']==mp['D']&&mp['R']==mp['L']) return 1;
        return 0;
    }
};