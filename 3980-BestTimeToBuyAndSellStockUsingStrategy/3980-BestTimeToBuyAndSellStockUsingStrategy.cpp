// Last updated: 10/27/2025, 7:04:48 PM
class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n=prices.size();
        vector<long long> sp(n+1,0), p(n+1,0);
        for(int i=0;i<n;i++){
            sp[i+1] = sp[i] + 1LL*prices[i]*strategy[i];
            p[i+1]  = p[i] + prices[i];
        }
        long long orgp=sp[n];
        long long prof=sp[n];
        
        for(int i=0;i+k<=n;i++){
            long long rp=sp[i+k]-sp[i];
            long long add=p[i+k]-p[i+k/2];
            long long masum=orgp-rp+add;
            prof=max(prof,masum);
        }
        return prof;
    }
};