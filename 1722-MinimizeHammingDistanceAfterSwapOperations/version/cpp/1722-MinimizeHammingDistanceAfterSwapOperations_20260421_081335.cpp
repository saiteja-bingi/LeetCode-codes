// Last updated: 21/4/2026, 8:13:35 am
1class Solution {
2public:
3    /*
4        it is like a connected components in graph
5
6    */
7    class DSU{
8    public:
9        vector<int>parent;
10        DSU(int n){
11            parent.resize(n);
12            for(int i=0;i<n;i++) parent[i]=i;
13        }
14        int find(int x){
15            if(parent[x]==x) return x;
16            return parent[x]=find(parent[x]);
17        }
18        void unite(int x,int y){
19            int px=find(x),py=find(y);
20            if(px!=py){
21                parent[px]=py;
22            }
23        }
24    };
25
26    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
27        int n=source.size();
28        DSU dsu(n);
29        for(auto&s:allowedSwaps){
30            dsu.unite(s[0],s[1]);
31        }
32        unordered_map<int,unordered_set<int>>clust;
33        for(int i=0;i<n;i++){
34            int x=dsu.find(i);
35            clust[x].insert(i);
36        }
37        int ans=0;
38        for(auto&[p,st]:clust){
39            unordered_map<int,int>freq;
40            for(auto it:st) freq[source[it]]++;
41            for(auto it:st){
42                if(freq[target[it]]>0){
43                    freq[target[it]]--;
44                }
45                else ans++;
46            }
47        }
48        return ans;
49    }
50};