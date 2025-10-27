// Last updated: 10/27/2025, 7:09:39 PM
class Solution {
public:
    int climbStairs(int n) {
        if(n<=1) return 1;
        int prev=1;
        int prev2=1;
        for(int i=2;i<=n;i++){
            int cur=prev+prev2;
            prev2=prev;
            prev=cur;
        }
        return prev;
    }
};