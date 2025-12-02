// Last updated: 12/2/2025, 7:40:17 PM
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
21        vector<int> dp(amount + 1, INT_MAX);
22        dp[0]=0;
23        for(int i=1;i<=amount;i++){
24            int mincoins = INT_MAX;
25            for (int c : coins) {
26                int res=INT_MAX-1;
27                if(i-c>=0) res =dp[i-c];
28                if (res != INT_MAX) {    
29                    mincoins = min(mincoins, 1 + res); 
30                }
31            }
32            dp[i]=mincoins;
33        }
34        return (dp[amount]==INT_MAX)?-1:dp[amount];
35    }
36};
37