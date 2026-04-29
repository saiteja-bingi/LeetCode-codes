// Last updated: 29/4/2026, 4:48:33 pm
1class Solution {
2public:
3    int minOperations(vector<vector<int>>& grid, int x) {
4        int n=grid.size(),m=grid[0].size();
5        if(n==1&&m==1) return 0;
6        vector<int>arr;
7        int sum=0;
8        for(int i=0;i<n;i++) for(int j=0;j<m;j++) {
9            arr.push_back(grid[i][j]);
10            sum+=grid[i][j];
11        }
12        sort(arr.begin(),arr.end());
13        n=arr.size();
14        int val=arr[(n+1)/2-1];
15        int c=0;
16        for(int i=0;i<n;i++){
17            if((val-arr[i])%x!=0) return -1;
18            c+=abs((val-arr[i])/x);
19        }
20        return c;
21
22    }
23};