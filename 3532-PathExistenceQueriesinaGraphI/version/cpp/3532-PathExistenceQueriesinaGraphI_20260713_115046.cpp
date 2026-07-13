// Last updated: 13/7/2026, 11:50:46 am
1class DSU{
2public:
3    vector<int>par,sz;
4    DSU(int n){
5        par.resize(n);
6        sz.assign(n,1);
7        iota(par.begin(),par.end(),0);
8    }
9    int find(int x){
10        if(par[x]==x) return x;
11        return par[x]=find(par[x]);
12    }
13    void unite(int x,int y){
14        x=find(x),y=find(y);
15        if(x==y) return;
16        if(sz[x]<sz[y]) swap(x,y);
17        par[y]=x;
18        sz[x]+=sz[y];
19    }
20    bool same(int x,int y){
21        return find(x)==find(y);
22    }
23};
24class Solution {
25public:
26    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
27        DSU dsu(n);
28        // int i=0;
29        for(int j=1;j<n;j++){
30            
31            if(nums[j]-nums[j-1]<=maxDiff) dsu.unite(j,j-1);
32        }
33        vector<bool>ans;
34        for(auto &it:queries){
35            if(dsu.same(it[0],it[1])){
36                ans.push_back(1);
37            }
38            else ans.push_back(0);
39        }
40        return ans;
41    }
42};