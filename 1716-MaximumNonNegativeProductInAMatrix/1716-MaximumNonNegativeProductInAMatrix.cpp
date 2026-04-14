// Last updated: 15/04/2026, 00:45:10
#define ll long long

class Solution {
public:
    ll mod=1e9+7;
    int maxProductPath(vector<vector<int>>& grid) {
        ll n=grid.size();
        ll m=grid[0].size();
        vector<vector<ll>>maxdp(n+1,vector<ll>(m+1,0));
        vector<vector<ll>>mindp(n+1,vector<ll>(m+1,0));
        maxdp[0][0]=mindp[0][0]=grid[0][0];
        for(int i=1;i<n;i++){
            maxdp[i][0]=mindp[i][0]=maxdp[i-1][0]*grid[i][0];
        }
        for(int j=1;j<m;j++){
            maxdp[0][j]=mindp[0][j]=maxdp[0][j-1]*grid[0][j];
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                vector<ll>temp;
                if(maxdp[i-1][j]!=LLONG_MIN) temp.push_back(maxdp[i-1][j]);
                if(maxdp[i][j-1]!=LLONG_MIN) temp.push_back(maxdp[i][j-1]);
                if(mindp[i-1][j]!=LLONG_MAX) temp.push_back(mindp[i-1][j]);
                if(mindp[i][j-1]!=LLONG_MAX) temp.push_back(mindp[i][j-1]);

                ll mi=LLONG_MAX,ma=LLONG_MIN;
                for(auto it:temp){
                    mi=min(mi,it*grid[i][j]);
                    ma=max(ma,it*grid[i][j]);
                }
                maxdp[i][j]=ma;
                mindp[i][j]=mi;
            }
        }
        if(maxdp[n-1][m-1]<0) return -1;
        return maxdp[n-1][m-1]%mod;

    }
};