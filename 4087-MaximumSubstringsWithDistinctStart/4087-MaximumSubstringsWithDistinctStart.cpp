// Last updated: 1/11/2026, 11:10:10 AM
class Solution {
public:
    int maxDistinct(string s) {
        int c=0;
        unordered_map<char,int>mp;
        for(auto it:s){
            if(mp[it]==0){
                mp[it]++;
                c++;
            }
        }
        return c;
    }
};