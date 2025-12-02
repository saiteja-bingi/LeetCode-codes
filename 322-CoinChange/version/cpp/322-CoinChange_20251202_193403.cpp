// Last updated: 12/2/2025, 7:34:03 PM
1class Solution {
2public:
3    int findsol(vector<int>& coins, int amount, vector<int>& dp) {
4        if (amount < 0) return INT_MAX; 
5        if (amount == 0) return 0;  
6
7        if (dp[amount] != -1) return dp[amount];
8
9        int mincoins = INT_MAX;
10        for (int c : coins) {
11            int res = findsol(coins, amount - c, dp);
12            if (res != INT_MAX) {    
13                mincoins = min(mincoins, 1 + res); 
14            }
15        }
16
17        return dp[amount] = mincoins;
18    }
19
20    int coinChange(vector<int>& coins, int amount) {
21        if (amount == 0) return 0;
22        vector<int> dp(amount + 1, -1);
23        int ans = findsol(coins, amount, dp);
24        return (ans == INT_MAX ? -1 : ans);
25    }
26};
27