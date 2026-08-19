// Last updated: 19/8/2026, 11:57:41 pm
class Solution {
public:
    int countValidPrefixes(string s) {
        int c1=0,c2=0,c=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='0') c1++;
            else c2++;
            if(abs(c1-c2)<=1) c++;
        }
        return c;
    }
};