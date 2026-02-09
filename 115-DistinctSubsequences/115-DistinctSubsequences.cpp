// Last updated: 09/02/2026, 21:08:22
class Solution {
public:
    int numDistinct(string s, string t) {
        if(t.size()>s.size()) return 0;
        long long n=s.size();
        long long m=t.size();
        vector<long long>dp(m+1,0);
        dp[0]=1;
        for(long long i=1;i<=n;i++){
            vector<long long>temp(m+1,0);
            temp[0]=1;
            for(long long j=1;j<=m;j++){
                long long ans=0;
                if(s[i-1]==t[j-1]){
                    ans+=(dp[j-1]+dp[j])%(1000000007);
                }
                else{
                    ans=dp[j]%(1000000007);
                }
                temp[j]=ans%(1000000007);
            }
            dp=temp;
        }
        return dp[m];
    }
};