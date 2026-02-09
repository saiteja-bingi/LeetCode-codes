// Last updated: 09/02/2026, 21:07:18
class Solution {
public:

    int findsol(vector<int>&p,int i,bool buy,bool cool,vector<vector<vector<int>>>&dp){
        if(i==p.size()) return 0;
        int a=INT_MIN,b=INT_MIN;
        if(dp[i][buy][cool]!=-1) return dp[i][buy][cool];
        if(buy){
            if(!cool) a=-p[i]+findsol(p,i+1,false,false,dp);
            b=findsol(p,i+1,true,false,dp);
        }
        else{
            a=p[i]+findsol(p,i+1,true,true,dp);
            b=findsol(p,i+1,false,false,dp);
        }
        return dp[i][buy][cool]=max(a,b);

    }
    int maxProfit(vector<int>& p) {
        int n=p.size();
        vector<vector<int>>dp(2,vector<int>(2,0));
        for(int i=n-1;i>=0;i--){
            vector<vector<int>>temp(2,vector<int>(2,0));
            for(int buy=0;buy<2;buy++){
                for(int cool=0;cool<2;cool++){
                    int a=INT_MIN,b=INT_MIN;
                    if(buy){
                        if(!cool) a=-p[i]+dp[0][0];
                        b=dp[1][0];
                    }
                    else{
                        a=p[i]+dp[1][1];
                        b=dp[0][0];
                    }
                    temp[buy][cool]=max(a,b);
                }
            }
            dp=temp;
        }
        return dp[1][0];
    }
};