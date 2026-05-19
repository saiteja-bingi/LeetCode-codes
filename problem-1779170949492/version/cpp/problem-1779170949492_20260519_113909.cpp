// Last updated: 19/5/2026, 11:39:09 am
1class Solution {
2public:
3    int minGenerations(vector<vector<int>>& points, vector<int>& target) {
4        int n=points.size();
5        vector<vector<vector<int>>>gen;
6        map<vector<int>,int>vis;
7        vector<vector<int>>first;
8
9        for(auto&p:points){
10            if(p==target) return 0;
11
12            if(!vis.count(p)){
13                first.push_back(p);
14                vis[p]=1;
15            }
16        }
17        gen.push_back(first);
18
19        for(int g=1;g<100;g++){
20            vector<vector<int>>all;
21            for(int k=0;k<g;k++){
22                for(auto &x:gen[k]){
23                    all.push_back(x);
24                }
25            }
26
27            vector<vector<int>>cg;
28            int m=all.size();
29
30            for(int i=0;i<m;i++){
31                for(int j=i+1;j<m;j++){
32                    if(all[i]==all[j]) continue;
33
34                    vector<int>temp(3);
35                    temp[0]=(all[i][0]+all[j][0])/2;
36                    temp[1]=(all[i][1]+all[j][1])/2;
37                    temp[2]=(all[i][2]+all[j][2])/2;
38                    if(temp==target) return g;
39
40                    if(!vis.count(temp)){
41                        cg.push_back(temp);
42                        vis[temp]++;
43                    }
44                }
45            }
46            if(cg.empty()) break;
47            gen.push_back(cg);
48        }
49        return -1;
50    }
51};