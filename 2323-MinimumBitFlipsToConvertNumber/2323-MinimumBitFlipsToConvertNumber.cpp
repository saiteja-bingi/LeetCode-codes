// Last updated: 10/27/2025, 7:05:57 PM
class Solution {
public:
    int countbits(int ans){
        int mask=1;
        int count=0;
        for(int i=0;i<32;i++){
            if(mask&ans) count++;
            mask=mask<<1;
        }
        return count;
    }
    int minBitFlips(int start, int goal) {
        int ans=start^goal;
        return countbits(ans);
    }
};