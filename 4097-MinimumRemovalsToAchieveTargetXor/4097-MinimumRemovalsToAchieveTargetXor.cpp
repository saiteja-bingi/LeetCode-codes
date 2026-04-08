// Last updated: 08/04/2026, 23:55:36
class Solution {
public:
    vector<vector<long long>>dp;
    long long find(auto&nums,long long req,long long i){
        if(i==nums.size()){
            if(req==0) return 0;
            return INT_MAX;
        }
        if(dp[i][req]!=-1) return dp[i][req];
        long long t=1+find(nums,req^nums[i],i+1);
        long long ut=find(nums,req,i+1);
        return dp[i][req]= min(t,ut);
    }

    /*
        the states should be req and i


        dp[i][xr] represnts min no of ele from i to get xr = req

        i goes from 1 to n
        req goes from 0 to max xor 

        i-->(1,n)
        req-->(0,range (1e4)==>2e4 bits)

        what are the base cases?
        if req==0:
            ans=0 always
        if(i==0):
            ans=-1 always why? we need some req but there are no ele

    */

    int minRemovals(vector<int>& nums, int target) {
        long long n=nums.size();
        long long xr=0;
        for(auto it:nums) xr^=it;
        if(xr==target) return 0;
        long long req=target^xr;
        // min ele req to make target=0;
        // min length of the subset whose xor values = target
        
        vector<vector<long long>>dp(n+1,vector<long long>(2e4+1,0));

        // base cases
        for(int r=0;r<=2e4;r++) dp[0][r]=-1;
        for(int i=0;i<=n;i++) dp[i][0]=0;

        for(int i=1;i<=n;i++){
            for(int xr=1;xr<=2e4;xr++){
                // take and untake
                long long ut=dp[i-1][xr];

                long long t=-1;
                long long k=-1;
                if((xr^nums[i-1])<=2e4) k=dp[i-1][xr^nums[i-1]];
                if(k!=-1) t=k+1;

                if(ut==-1) dp[i][xr]=t;
                else if(t==-1) dp[i][xr]=ut;
                else{
                    dp[i][xr]=min(t,ut);
                }

            }
        }
        long long ans=dp[n][req];
        return (int)ans;
        

    }
};