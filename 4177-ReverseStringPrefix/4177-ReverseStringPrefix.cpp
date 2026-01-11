// Last updated: 1/11/2026, 11:09:48 AM
class Solution {
public:
    string reversePrefix(string s, int k) {
        string ans="";
        for(int i=k-1;i>=0;i--){
            ans+=s[i];
        }
        for(int i=k;i<s.size();i++){
            ans+=s[i];
        }
        return ans;
    }
};