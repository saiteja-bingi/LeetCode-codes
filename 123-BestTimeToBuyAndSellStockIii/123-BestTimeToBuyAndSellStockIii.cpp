// Last updated: 09/02/2026, 21:08:16
class Solution {
public:
    int maxProfit(vector<int>& p) {
        long long n=p.size();
        vector<vector<long long>>dp(3,vector<long long>(2,0));
        for(int i=n-1;i>=0;i--){
        vector<vector<long long>>temp(3,vector<long long>(2,0));
            for(int j=1;j<3;j++){
                for(int k=0;k<2;k++){
                    int a=INT_MIN,b=INT_MIN;
                    if(k){
                        a=-p[i]+dp[j][0];
                        b=dp[j][1];
                    }
                    else {
                        a=p[i]+dp[j-1][1];
                        b=dp[j][0];
                    }
                    temp[j][k]= max(a,b);
                }
            }
                dp=temp;
        }
        return dp[2][1];
        
    }
};