// Last updated: 31/7/2026, 11:06:45 pm
1class Solution {
2public:
3    int largestInteger(int n, int s) {
4        if(9*n<s) return -1;
5        int ans=0,sum=0;
6        while(n--){
7            ans=ans*10+min(9,s-sum);
8            sum+=min(9,s-sum);
9        }
10        return ans;
11    }
12};