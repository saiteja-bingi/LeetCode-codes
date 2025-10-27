// Last updated: 10/27/2025, 7:08:48 PM
class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;
        unsigned int mask = 1;
        for(int i = 0; i < 32; i++) {
            if (n & mask) count++;
            mask = mask << 1;
        }
        return count;
    }
};
