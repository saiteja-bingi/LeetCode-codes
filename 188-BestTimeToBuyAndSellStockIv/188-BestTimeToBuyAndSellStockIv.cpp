// Last updated: 09/02/2026, 21:07:35
class Solution {
public:
    int maxProfit(int k, vector<int>& p) {
        long long n=p.size();
        vector<vector<long long>>dp(k+1,vector<long long>(2,0));
        for(long long i=n-1;i>=0;i--){
            vector<vector<long long>>temp(k+1,vector<long long>(2,0));
            for(long long nt=1;nt<k+1;nt++){
                for(long long buy=0;buy<2;buy++){
                    long long a=INT_MIN,b=INT_MIN;
                    if(buy){
                        a=-p[i]+dp[nt][0];
                        b=dp[nt][1];
                    }
                    else{
                        a=p[i]+dp[nt-1][1];
                        b=dp[nt][0];
                    }
                    temp[nt][buy]=max(a,b);
                }
            }
                dp=temp;
        }

        return dp[k][1];
    }
};