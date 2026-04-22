// Last updated: 22/4/2026, 6:14:09 pm
1class Solution {
2public:
3    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
4        unordered_map<string,bool>mp;
5        for(auto &it:dictionary){
6            mp[it]=true;
7        }
8        vector<string>ans;
9        for(auto &it:queries){
10            if(mp.count(it)){
11                ans.push_back(it);
12                continue;
13            }
14            int m=it.size();
15            for(auto &d:dictionary){
16                int c=0;
17                for(int i=0;i<m;i++){
18                    if(d[i]!=it[i]) c++;
19                    if(c>2) break;
20                }
21                if(c<=2){
22                    ans.push_back(it);
23                    break;
24                }
25            }
26        }
27
28        return ans;
29    }
30};