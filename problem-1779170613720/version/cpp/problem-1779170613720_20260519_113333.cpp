// Last updated: 19/5/2026, 11:33:33 am
1class Solution {
2public:
3    int minGenerations(vector<vector<int>>& points, vector<int>& target) {
4
5        vector<vector<vector<int>>> gen;
6        map<vector<int>, int> vis;
7
8        vector<vector<int>> first;
9
10        for (auto &p : points) {
11            if (p == target) return 0;
12
13            if (!vis.count(p)) {
14                vis[p] = 1;
15                first.push_back(p);
16            }
17        }
18
19        gen.push_back(first);
20
21        for (int g = 1; g < 100; g++) {
22
23            vector<vector<int>> all;
24
25            for (int k = 0; k < g; k++) {
26                for (auto &x : gen[k]) {
27                    all.push_back(x);
28                }
29            }
30
31            vector<vector<int>> cur;
32
33            int m = all.size();
34
35            for (int i = 0; i < m; i++) {
36                for (int j = i + 1; j < m; j++) {
37
38                    if (all[i] == all[j]) continue;
39
40                    vector<int> temp(3);
41
42                    temp[0] = (all[i][0] + all[j][0]) / 2;
43                    temp[1] = (all[i][1] + all[j][1]) / 2;
44                    temp[2] = (all[i][2] + all[j][2]) / 2;
45
46                    if (temp == target) return g;
47
48                    if (!vis.count(temp)) {
49                        vis[temp] = 1;
50                        cur.push_back(temp);
51                    }
52                }
53            }
54
55            if (cur.empty()) break;
56
57            gen.push_back(cur);
58        }
59
60        return -1;
61    }
62};