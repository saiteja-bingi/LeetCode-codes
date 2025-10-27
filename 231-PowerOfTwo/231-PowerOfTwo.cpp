// Last updated: 10/27/2025, 7:07:59 PM
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0) return false;
        return !(n&(n-1));
    }
};