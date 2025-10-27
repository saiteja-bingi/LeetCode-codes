// Last updated: 10/27/2025, 7:09:22 PM
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i,bestbuy=prices[0],mp=0;
        for(i=1;i<prices.size();i++){
            if(prices[i]>bestbuy){
                mp=max(mp,prices[i]-bestbuy);
            }
            bestbuy=min(bestbuy,prices[i]);
        }
    return mp;
    }
};