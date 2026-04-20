// Last updated: 20/4/2026, 7:42:00 am
1class Solution {
2public:
3    int maxDistance(vector<int>& col) {
4        int ans=0,n=col.size();
5        for(int i=1;i<n;i++){
6            if(col[i]!=col[0]) ans=max(ans,i);
7            if(col[i]!=col[n-1]) ans=max(ans,n-i-1);
8        }
9        return ans;
10    }
11};