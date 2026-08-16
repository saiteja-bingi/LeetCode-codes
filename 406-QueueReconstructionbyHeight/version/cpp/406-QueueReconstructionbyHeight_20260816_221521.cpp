// Last updated: 16/8/2026, 10:15:21 pm
1class Solution {
2public:
3    vector<int>tree;
4    void build(int node,int l,int r){
5        if(l==r){
6            tree[node]=1;
7            return;
8        }
9        int mid=l+(r-l)/2;
10        build(2*node,l,mid);
11        build(2*node+1,mid+1,r);
12        tree[node]=tree[2*node]+tree[2*node+1];
13    }
14    int find(int node,int l,int r,int k){
15        if(l==r) return l;
16        int mid=l+(r-l)/2;
17        int left=tree[2*node];
18        if(k<=left){
19            return find(2*node,l,mid,k);
20        }
21        return find(2*node+1,mid+1,r,k-left);
22    }
23
24    void update(int node,int l,int r,int k){
25        if(l==r){
26            tree[node]=0;
27            return;
28        }
29        int mid=l+(r-l)/2;
30        if(k<=mid){
31            update(2*node,l,mid,k);
32        }
33        else update(2*node+1,mid+1,r,k);
34        tree[node]=tree[2*node]+tree[2*node+1];
35    }
36    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
37        int n=people.size();
38        sort(people.begin(),people.end(),[](auto&a, auto &b){
39            if(a[0]!=b[0]){
40                return a[0]<b[0];
41            }
42            return a[1]>b[1];
43        });
44
45        tree.resize(4*n);
46        build(1,0,n-1);
47        vector<vector<int>>ans(n);
48        for(auto&p:people){
49            int pos=find(1,0,n-1,p[1]+1);
50            ans[pos]=p;
51            update(1,0,n-1,pos);
52        }
53        return ans;
54    }
55};