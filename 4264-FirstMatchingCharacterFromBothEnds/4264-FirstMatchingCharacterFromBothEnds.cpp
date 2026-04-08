// Last updated: 08/04/2026, 23:54:26
class Solution {
public:
    int firstMatchingIndex(string s) {
        int n=s.size();
        for(int i=0;i<=n-i-1;i++){
            if(s[i]==s[n-i-1]) return i;
        }
        return -1;
    }
};