// Last updated: 15/8/2026, 8:11:21 pm
1class Solution {
2public:
3    int minOperations(string s) {
4        int n=s.size();
5        int ans=INT_MAX;
6        for(int i=0;i<n;i++){
7            int c=i;
8            for(int j=0;j<n/2;j++){
9                int a=(j+i)%n,b=(n-j-1+i)%n;
10                char x=s[a],z=s[b];
11                c+=min((z-x+26)%26,(x-z+26)%26);
12            }
13            ans=min(ans,c);
14        }
15        return ans;
16    }
17};