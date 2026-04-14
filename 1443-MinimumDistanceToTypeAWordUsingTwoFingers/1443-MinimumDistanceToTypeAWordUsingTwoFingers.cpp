// Last updated: 15/04/2026, 00:45:20
class Solution {
public:
    /*
        dp[i][j][k]=>
        i-> first i positions are complete
        j-> 1 at jth character
        k-> 2 at kth charcter
    */
    int find(int a,int b){
        int x1=a/6,x2=b/6,y1=a%6,y2=b%6;
        return abs(x1-x2)+abs(y1-y2);
    }
    int minimumDistance(string word) {
        int n=word.size();
        long long dp[27][27];
        fill(&dp[0][0], &dp[0][0]+27*27,INT_MAX);
        for(int i=0;i<n;i++){
            int c=word[i]-'A';
            long long temp[27][27];
            fill(&temp[0][0], &temp[0][0]+27*27,INT_MAX);
            for(int j=0;j<26;j++){
                for(int k=0;k<26;k++){
                    if(i==0) dp[j][k]=0;
                    temp[j][c]=min(temp[j][c],dp[j][k]+find(k,c));
                    temp[c][k]=min(temp[c][k],dp[j][k]+find(j,c));
                }
            }
            memcpy(dp, temp, sizeof(dp));
        }
        int ans=INT_MAX;
        for(int j=0;j<26;j++){
            for(int k=0;k<26;k++){
                ans=min(1ll*ans,dp[j][k]);
            }
        }
        return ans;
    }
};