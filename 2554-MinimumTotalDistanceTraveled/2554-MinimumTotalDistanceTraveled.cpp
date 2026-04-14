// Last updated: 15/04/2026, 00:44:43
#define ll long long
#define all(x) x.begin(), x.end()
class Solution {
public:
    /*
        initially all are broken ->need to repair
        robot can move to left or right
        choose any factory which has limit
        minimize the total distance

        DP:
            what state can be?
            min distance to fix first j robots usign 1st i factories
            dp[i][j]=mindis
        
        for 0 robots i factories->min dis=0
    */

    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(all(robot));
        sort(all(factory));
        int n=robot.size();
        int m=factory.size();
        
        ll dp[m+1][n+1];
        fill(&dp[0][0],&dp[0][0]+(m+1)*(n+1),LLONG_MAX);
        for(int i=0;i<=m;i++) dp[i][0]=0;

        // i->factor,j->robot
        for(int i=1;i<=m;i++){
            ll l=factory[i-1][1];
            ll p=factory[i-1][0];
            for(int j=1;j<=n;j++){
                dp[i][j]=dp[i-1][j];
                ll d=0;
                for(int k=1;k<=l;k++){
                    if(j-k<0) break;
                    d+=abs(p-robot[j-k]);
                    if(dp[i-1][j-k]!=LLONG_MAX){
                        dp[i][j]=min(dp[i][j],dp[i-1][j-k]+d);
                    }
                }
            }
        }
        return dp[m][n];

    }
};