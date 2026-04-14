// Last updated: 15/04/2026, 00:43:37
class Solution {
public:
    #define ll long long
    /*
        _w_r__r__w__r___w_w__r__r 
        1) bullet -> robot no effect
        2) robot and wall ->robot
        3) only one bullet
        4) atmost x distance
        5) maxium walls destroyed

        dp[i][0] ith shoots left
        dp[i][1] ith shoots right

        if we shoots in right the next robot can shoot in left
        so there is a robotsping
        if we shoot right there is no robotsping

        1) robot shoots in right direction
            no robotsping because
            <-prev-> cur->
        2) shoots in left
            case 1: no overllping
                <- prev <- cur
            case 2: robotsping
                prev-><- cur;
                prev destroyed walls + curleft walls-robotsping walls

            robotsping range=left_cur,right_prev

    */

    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        int n=robots.size(),m=walls.size();

        vector<vector<ll>>rob;
        for(int i=0;i<n;i++) rob.push_back({robots[i],distance[i]});
        sort(rob.begin(),rob.end());
        sort(walls.begin(),walls.end());
        rob.push_back({INT_MAX,0LL});

        auto findrobots=[&](ll l ,ll r)->ll{
            if(l>r) return 0;
            auto up=upper_bound(walls.begin(),walls.end(),r);
            auto lo=lower_bound(walls.begin(),walls.end(),l);
            return up-lo;
        };
        vector<array<ll,2>>dp(n);
        // shoot left
        dp[0][0]=findrobots(rob[0][0]-rob[0][1],rob[0][0]);
        // shoot right
        if(n>1){
            dp[0][1]=findrobots(rob[0][0],min(rob[1][0]-1,rob[0][0]+rob[0][1]));
        }
        else{
            dp[0][1]=findrobots(rob[0][0],rob[0][0]+rob[0][1]);
        }

        for(int i=1;i<n;i++){
            // right
            dp[i][1]=max(dp[i-1][0],dp[i-1][1])+
            findrobots(rob[i][0],min(rob[i+1][0]-1,rob[i][0]+rob[i][1]));

            // left
            // no overlap
            ll total_left=findrobots(max(rob[i-1][0]+1,rob[i][0]-rob[i][1]),rob[i][0]);
            dp[i][0]=dp[i-1][0]+total_left;

            // overlap
            ll leftst=max(rob[i][0]-rob[i][1],rob[i-1][0]+1);
            ll preven=min(rob[i-1][0]+rob[i-1][1],rob[i][0]-1);

            ll overlap=findrobots(leftst,preven);
            ll res=dp[i-1][1]+total_left-overlap;

            dp[i][0]=max(res,dp[i][0]);
        }
        return max(dp[n-1][0],dp[n-1][1]);

    }
};