// Last updated: 09/08/2026, 08:09:39
1class Solution {
2public:
3    double minPrice(vector<int>& prices, vector<int>& discounts) {
4        sort(prices.rbegin(),prices.rend());
5        sort(discounts.rbegin(),discounts.rend());
6        double t=0.0;
7        int k=min(prices.size(),discounts.size());
8        for(int i=0;i<k;i++){
9            t+=(double)prices[i]*(100-discounts[i])/100.0;
10        }
11        for(int i=k;i<prices.size();i++) t+=prices[i];
12        return t;
13    }
14};