// Last updated: 15/04/2026, 00:45:00
class Solution {
public:
    bool checkOnesSegment(string s) {
        int n=s.size();
        bool k=true;
        for(int i=1;i<n;i++){
            if(s[i]=='1'&&s[i-1]=='0') return false;
        }
        return true;
    }
};