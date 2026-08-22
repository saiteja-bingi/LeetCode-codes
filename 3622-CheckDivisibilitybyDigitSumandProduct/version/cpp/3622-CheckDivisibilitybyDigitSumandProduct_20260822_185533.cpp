// Last updated: 22/8/2026, 6:55:33 pm
1class Solution {
2public:
3    bool checkDivisibility(int n) {
4        int sum=0,product=1;
5        int num=n;
6        while(n>0){
7            int rem=n%10;
8            sum+=rem;
9            product*=rem;
10            n=n/10;
11        }
12        if(num%(sum+product)==0) return true;
13        else return false;
14    }
15};