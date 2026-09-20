// Last updated: 20/9/2026, 8:04:45 am
1class Solution {
2public:
3    int countIntersectingIntervals(vector<vector<int>>& i) {
4        int c=0;
5        sort(i.begin(),i.end());
6        for(int j=0;j<i.size();j++){
7            for(int k=j+1;k<i.size();k++){
8                if(i[k][0]<=i[j][1]){
9                    c++;
10                }
11            }
12        }
13        return c;
14    }
15};