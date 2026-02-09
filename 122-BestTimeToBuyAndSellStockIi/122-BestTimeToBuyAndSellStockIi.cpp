// Last updated: 09/02/2026, 21:08:18
class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n=p.size();
        vector<int>dp(2,-1);
        dp[0]=0;
        dp[1]=INT_MIN;
        for(int i=1;i<=n;i++){
            vector<int>temp(2,-1);
            temp[0]=0;
            temp[1]=INT_MIN;
            for(int buy=0;buy<2;buy++){
                if(buy){
                    int a=-p[i-1]+dp[0];
                    int b=dp[1];
                    temp[buy]= max(a,b);
                }
                else{
                    int a=p[i-1]+dp[1];
                    int b=dp[0];
                    temp[buy]= max(a,b);
                }
                dp=temp;
            }
        }
        return dp[0];
    }
};