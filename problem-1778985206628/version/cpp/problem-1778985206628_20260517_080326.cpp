// Last updated: 17/5/2026, 8:03:26 am
1class Solution {
2public:
3    bool isAdjacentDiffAtMostTwo(string s) {
4        int sum=0;
5        for(int i=0;i<s.size()-1;i++){
6            sum=abs((s[i]-'0')-(s[i+1]-'0'));
7            if(sum>2) return false;
8        }
9        return true;
10    }
11};