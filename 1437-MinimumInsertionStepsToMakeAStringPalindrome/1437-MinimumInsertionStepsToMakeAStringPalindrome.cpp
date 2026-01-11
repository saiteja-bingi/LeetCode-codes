// Last updated: 1/11/2026, 10:03:28 PM
class Solution {
public:
    int minInsertions(string s) {
        int n=s.size();
        vector<int>dp(n+1,0);
        string s2=s;
        reverse(s2.begin(),s2.end());
        for(int i=1;i<=n;i++){
            vector<int>temp(n+1,0);
            for(int j=1;j<=n;j++){
                if(s[i-1]==s2[j-1]){
                    temp[j]=1+dp[j-1];
                }
                else{
                    int l=dp[j];
                    int r=temp[j-1];
                    temp[j]=max(l,r);
                }
            }
            dp=temp;
        }
        return n-dp[n];
    }
};