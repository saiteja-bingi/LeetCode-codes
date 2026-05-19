// Last updated: 19/5/2026, 10:32:53 am
1class Solution {
2public:
3    bool validDigit(int n, int x) {
4        int c=0,y=0;
5        while(n>0){
6            c+=(n%10==x);
7            y=(n%10==x);
8            n/=10;
9        }
10        // cout<<y<<" "<<c<<endl;
11        return (!y)&&c;
12    }
13};