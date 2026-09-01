// Last updated: 1/9/2026, 7:20:46 pm
1class Solution {
2public:
3    int minMoves(vector<string>& classroom, int energy) {
4        int m = classroom.size();
5        int n = classroom[0].size();
6
7        vector<vector<int>> id(m, vector<int>(n, -1));
8
9        int k = 0;
10        int sr = 0, sc = 0;
11
12        for (int r = 0; r < m; r++) {
13            for (int c = 0; c < n; c++) {
14                if (classroom[r][c] == 'S') {
15                    sr = r;
16                    sc = c;
17                } else if (classroom[r][c] == 'L') {
18                    id[r][c] = k++;
19                }
20            }
21        }
22
23        if (k == 0) return 0;
24
25        int totalMask = (1 << k) - 1;
26
27        vector<vector<vector<int>>> best(
28            m, vector<vector<int>>(n, vector<int>(1 << k, -1))
29        );
30
31        struct State {
32            int r, c, mask, e, moves;
33        };
34
35        queue<State> q;
36
37        best[sr][sc][0] = energy;
38        q.push({sr, sc, 0, energy, 0});
39
40        int dr[] = {-1, 1, 0, 0};
41        int dc[] = {0, 0, -1, 1};
42
43        while (!q.empty()) {
44            State cur = q.front();
45            q.pop();
46
47            for (int d = 0; d < 4; d++) {
48                int nr = cur.r + dr[d];
49                int nc = cur.c + dc[d];
50
51                if (nr < 0 || nr >= m || nc < 0 || nc >= n)
52                    continue;
53
54                if (classroom[nr][nc] == 'X')
55                    continue;
56
57                int ne = cur.e - 1;
58
59                if (ne < 0)
60                    continue;
61
62                int nmask = cur.mask;
63
64                if (classroom[nr][nc] == 'R') {
65                    ne = energy;
66                }
67
68                if (classroom[nr][nc] == 'L') {
69                    nmask |= (1 << id[nr][nc]);
70                }
71
72                if (nmask == totalMask) {
73                    return cur.moves + 1;
74                }
75
76                if (ne <= best[nr][nc][nmask])
77                    continue;
78
79                best[nr][nc][nmask] = ne;
80
81                q.push({nr, nc, nmask, ne, cur.moves + 1});
82            }
83        }
84
85        return -1;
86    }
87};