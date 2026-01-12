// Last updated: 1/12/2026, 12:27:39 PM
class Solution {
public:
    int maxProfit(vector<int>& p, int fee) {
        long long n=p.size();
        vector<long long>dp(2,0);
        for(long long i=n-1;i>=0;i--){
            vector<long long>temp(2,0);
            for(long long buy=0;buy<2;buy++){
                long long a=INT_MIN,b=INT_MIN;
                if(buy){
                    a=-p[i]+dp[0];
                    b=dp[1];
                }
                else{
                    a=p[i]+dp[1]-fee;
                    b=dp[0];
                }
                temp[buy]= max(a,b);
            }
            dp=temp;
        }
        return dp[1];
    }
};