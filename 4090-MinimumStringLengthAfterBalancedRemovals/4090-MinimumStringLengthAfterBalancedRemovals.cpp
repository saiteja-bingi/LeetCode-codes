// Last updated: 12/1/2025, 7:13:14 PM
class Solution {
public:
    int minLengthAfterRemovals(string s) {
        int as=count(s.begin(),s.end(),'a');
        int bs=count(s.begin(),s.end(),'b');
        return abs(as-bs);
    }
};