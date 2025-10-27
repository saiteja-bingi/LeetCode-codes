// Last updated: 10/27/2025, 7:07:54 PM
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        unordered_map<char,int>mp1;
        for(int i=0;i<s.size();i++){
            mp1[s[i]]++;
        }
        for(int i=0;i<s.size();i++){
            mp1[t[i]]--;
            if(mp1[t[i]]<0) return false;

        }
        return true;
    }
};