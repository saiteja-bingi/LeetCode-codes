// Last updated: 24/4/2026, 8:19:16 am
1class Solution {
2public:
3    int furthestDistanceFromOrigin(string moves) {
4        int c1=0,c2=0;
5        for(auto it:moves){
6            if(it=='L') c1++;
7            if(it=='R') c2++;
8        }
9        int n=moves.size();
10        return abs(c1-c2)+n-c1-c2;
11    }
12};