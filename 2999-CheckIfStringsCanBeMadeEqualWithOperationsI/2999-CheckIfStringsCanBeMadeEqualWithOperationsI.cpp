// Last updated: 15/04/2026, 00:44:34
class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        map<char,int>mp1,mp2;
        for(int i=0;i<s1.size();i++){
            if(i%2==0){
                mp1[s1[i]]++;
                mp1[s2[i]]--;
            }
            else{
                mp2[s1[i]]++;
                mp2[s2[i]]--;
            }
        }
        for(auto[x,y]:mp1) if(y) return false;
        for(auto [x,y]:mp2) if(y) return false;
        return true;
    }
};