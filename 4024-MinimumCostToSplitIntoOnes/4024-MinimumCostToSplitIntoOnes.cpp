// Last updated: 15/04/2026, 00:43:32
class Solution {
public:
    int minCost(int n) {
        vector<int> cost(500+1);
        cost[1]=0;
        cost[2]=1;
        for(int i=3;i<=500;i++){
            int ele=cost[i/2];
            cost[i]=i/2*(i-i/2)+ele+cost[i-i/2];
        }
        return cost[n];
    }
};