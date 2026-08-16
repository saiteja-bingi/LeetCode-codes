// Last updated: 16/8/2026, 9:38:29 pm
1class Solution {
2public:
3    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
4        int n=people.size();
5        sort(people.begin(),people.end(),[](auto& a, auto &b){
6            if(a[0]!=b[0]){
7                return a[0]>b[0];
8            }
9            return a[1]<b[1];
10        });
11        vector<vector<int>>ans;
12        for(auto &p:people){
13            ans.insert(ans.begin()+p[1],p);
14        }
15        return ans;
16
17    }
18};
19
20