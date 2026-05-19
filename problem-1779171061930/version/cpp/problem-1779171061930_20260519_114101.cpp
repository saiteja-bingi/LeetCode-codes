// Last updated: 19/5/2026, 11:41:01 am
1class Solution {
2public:
3    int minGenerations(vector<vector<int>>& points, vector<int>& target) {
4        int n=points.size();
5        vector<vector<vector<int>>>gen;
6        map<vector<int>,int>vis;
7        vector<vector<int>>temp;
8        for(int i=0;i<n;i++){
9            if(points[i]==target) return 0;
10            if(vis.count(points[i])) continue;
11            temp.push_back(points[i]);
12            vis[points[i]]=1;
13        }
14        gen.push_back(temp);
15
16        for(int g=1;g<100;g++){
17            vector<vector<int>>p;
18            for(int k=0;k<g;k++){
19                for(auto x:gen[k]){
20                    // if(vis.count(x)) continue;
21                    p.push_back(x);
22                    vis[x]++;
23                }
24            }
25            vector<vector<int>>cg;
26            int m=p.size();
27            for(int i=0;i<m;i++){
28                for(int j=i+1;j<m;j++){
29                    // if(p[i]==p)
30                    vector<int>temp(3);
31                    temp[0]=(p[i][0]+p[j][0])/2;
32                    temp[1]=(p[i][1]+p[j][1])/2;
33                    temp[2]=(p[i][2]+p[j][2])/2;
34                    if(temp==target) return g;
35                    if(vis.count(temp)) continue;
36                    cg.push_back(temp);
37                    vis[temp]++;
38                }
39            }
40            if(cg.empty()) break;
41            gen.push_back(cg);
42        }
43        return -1;
44    }
45};