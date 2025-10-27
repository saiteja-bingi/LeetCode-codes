// Last updated: 10/27/2025, 7:06:31 PM
class Solution {
public:
    vector<int>dp;
    int fib(int n){
        dp.resize(n+1,-1);
        return helper(n);
    }
    int helper(int n) {
        if(n<=1) return n;

        if(dp[n]!=-1) return dp[n];

        dp[n]=helper(n-1)+helper(n-2);
        return dp[n];
    }
};