// Last updated: 10/27/2025, 7:08:42 PM
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size()!=t.size()) return false;
        unordered_map<char,char>mp;
        unordered_map<char,int>mp1;
        for(int i=0;i<s.size();i++){
            if(mp.find(s[i])==mp.end()&&mp1.find(t[i])==mp1.end()){
                mp[s[i]]=t[i];
                mp1[t[i]]=s[i];
            }
            else if(mp[s[i]]!=t[i]||mp1[t[i]]!=s[i]){
                return false;
            }
        }
        return true;
    }
};