// Last updated: 1/11/2026, 10:03:43 PM
class Solution {
public:
    int minDistance(string w1, string w2) {
        int n=w1.size();
        int m=w2.size();
        vector<int>dp(m+1,0);
        for(int i=1;i<=n;i++){
            vector<int>temp(m+1,0);
            for(int j=1;j<=m;j++){
                if(w1[i-1]==w2[j-1]){
                    temp[j]=1+dp[j-1];
                }
                else{
                    int l=temp[j-1];
                    int r=dp[j];
                    temp[j]=max(l,r);
                }
            }
            dp=temp;
        }
        cout<<dp[m]<<endl;
        return m+n-2*(dp[m]);
    }
};