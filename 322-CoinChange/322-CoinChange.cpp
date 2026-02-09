// Last updated: 09/02/2026, 21:07:16
class Solution {
public:
    int findsol(vector<int>& coins, int amount, vector<int>& dp) {
        if (amount < 0) return INT_MAX; 
        if (amount == 0) return 0;  

        if (dp[amount] != -1) return dp[amount];

        int mincoins = INT_MAX;
        for (int c : coins) {
            int res = findsol(coins, amount - c, dp);
            if (res != INT_MAX) {    
                mincoins = min(mincoins, 1 + res); 
            }
        }

        return dp[amount] = mincoins;
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0]=0;
        for(int i=1;i<=amount;i++){
            int mincoins = INT_MAX;
            for (int c : coins) {
                int res=INT_MAX-1;
                if(i-c>=0) res =dp[i-c];
                if (res != INT_MAX) {    
                    mincoins = min(mincoins, 1 + res); 
                }
            }
            dp[i]=mincoins;
        }
        return (dp[amount]==INT_MAX)?-1:dp[amount];
    }
};
