// Last updated: 20/4/2026, 7:42:58 am
class Solution {
public:
    int mirrorDistance(int n) {
        int r=0,k=n;
        for(;n>0;n/=10) r=r*10+n%10;
        return abs(k-r);
    }
};