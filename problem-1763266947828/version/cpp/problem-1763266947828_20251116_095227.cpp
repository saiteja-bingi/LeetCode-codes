// Last updated: 11/16/2025, 9:52:27 AM
class Solution {
public:
    int minLengthAfterRemovals(string s) {
        int as=count(s.begin(),s.end(),'a');
        int bs=count(s.begin(),s.end(),'b');
        return abs(as-bs);
    }
};