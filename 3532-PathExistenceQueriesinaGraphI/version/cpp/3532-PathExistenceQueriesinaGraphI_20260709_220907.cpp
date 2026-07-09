// Last updated: 9/7/2026, 10:09:07 pm
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
27        sort(nums.begin(),nums.end());
28        DSU dsu(n);
29        int i=0;
30        for(int j=1;j<n;j++){
31            while(i<j&&nums[j]-nums[i]>maxDiff){
32                i++;
33            }
34            dsu.unite(i,j);
35        }
36        vector<bool>ans;
37        for(auto &it:queries){
38            if(dsu.same(it[0],it[1])){
39                ans.push_back(1);
40            }
41            else ans.push_back(0);
42        }
43        return ans;
44    }
45};