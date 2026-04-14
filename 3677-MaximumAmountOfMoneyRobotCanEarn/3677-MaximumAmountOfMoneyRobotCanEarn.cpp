// Last updated: 15/04/2026, 00:44:24
class Solution {
public:

    /*
        so dp huh?
        from (0,0)->(n-1,m-1)
        if(coin>=0) add coins
        if(coins<0){
            atmost 2 can make 0
            else take negative coins
        }
        dp[i][j][k] represents coins at (i,j) point after using k nutralizes
    */
    int maximumAmount(vector<vector<int>>& coins) {
        long long n=coins.size();
        long long m=coins[0].size();
        vector<vector<long long>>dp(m,vector<long long>(3,LLONG_MIN));
        for(int i=0;i<3;i++){
            if(i==0||coins[0][0]>=0) dp[0][i]=coins[0][0];
            else if(i<3) dp[0][i]=0;
        }
        for(long long i=0;i<n;i++){
            vector<vector<long long>>temp(m,vector<long long>(3,LLONG_MIN));
            for(long long j=0;j<m;j++){
                if(i==0&&j==0){
                    temp[0]=dp[0];
                    continue;
                }
                for(long long k=0;k<3;k++){
                    long long a=LLONG_MIN,b=LLONG_MIN;
                    long long c=coins[i][j];
                    if(i-1>=0) a=dp[j][k];
                    if(j-1>=0) b=temp[j-1][k];
                    long long best=max(a,b);
                    if(best==LLONG_MIN) continue;

                    if(c>=0){
                        temp[j][k]=max(temp[j][k],best+c);
                    }
                    else{
                        temp[j][k]=max(temp[j][k],best+c);
                        if(k<2) temp[j][k+1]=max(temp[j][k+1],best);
                    }
                }
            }
            dp=temp;
        }
        long long ans=LLONG_MIN;
        for(long long i=0;i<3;i++) ans=max(ans,dp[m-1][i]);
        return ans;
        
    }
};