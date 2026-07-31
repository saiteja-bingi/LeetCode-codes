// Last updated: 31/7/2026, 11:20:20 pm
1class Solution {
2public:
3    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& s1, vector<vector<int>>& s2) {
4        vector<vector<int>>ans;
5        int i=0,j=0,n=s1.size(),m=s2.size();
6        while(i<n&&j<m){
7            if(s1[i][0]==s2[j][0]){
8                ans.push_back({s1[i][0],s1[i][1]+s2[j][1]});
9                i++;
10                j++;
11                continue;
12            }
13            if(s1[i][0]>s2[j][0]){
14                ans.push_back({s2[j][0],s2[j][1]+s1[i][1]});
15                j++;
16            }
17            else{
18                ans.push_back({s1[i][0],s1[i][1]+s2[j][1]});
19                i++;
20            }
21        }
22        while(i<n){
23            ans.push_back({s1[i][0],s1[i][1]});
24            i++;
25        }
26        while(j<m){
27            ans.push_back({s2[j][0],s2[j][1]});
28            j++;
29        }
30        return ans;
31    }
32};