// Last updated: 09/08/2026, 08:46:35
1#include<bits/stdc++.h>
2using namespace std;
3typedef long long ll;
4
5struct Node{
6int lo,hi,cnt,fp,lp;
7ll val;
8int ts,te,ls,le;
9};
10
11struct Tree {
12    int n;
13    vector<Node> tr;
14    vector<int> p;
15
16    Tree(int n_): n(n_), tr(4*n_), p(n_,0) {}
17
18    Node leaf(int i){
19        Node nd;
20        nd.lo=nd.hi=i;
21        nd.cnt=p[i];
22        nd.fp=nd.lp=(p[i]?i:-1);
23        nd.ts=i; nd.te=i; nd.ls=i; nd.le=i;
24        nd.val=0;
25        return nd;
26    }
27
28    Node merge(const Node&L, const Node&R){
29        Node nd;
30        nd.lo=L.lo; nd.hi=R.hi;
31        nd.cnt=L.cnt+R.cnt;
32        nd.fp=(L.cnt>0)?L.fp:R.fp;
33        nd.lp=(R.cnt>0)?R.lp:L.lp;
34
35        if(R.cnt>0){ nd.ts=R.ts; nd.te=R.te; }
36        else { nd.ts=L.ts; nd.te=R.hi; }
37
38        if(L.cnt>0){ nd.ls=L.ls; nd.le=L.le; }
39        else { nd.ls=L.lo; nd.le=R.le; }
40
41        ll a=L.te-L.ts+1, b=R.le-R.ls+1;
42        ll cr=a*b;
43        if(a>0 && b>0) cr--;
44
45        nd.val=L.val+R.val+cr;
46        return nd;
47    }
48
49    void build(int node,int lo,int hi){
50        if(lo==hi){ tr[node]=leaf(lo); return; }
51        int mid=(lo+hi)/2;
52        build(2*node,lo,mid);
53        build(2*node+1,mid+1,hi);
54        tr[node]=merge(tr[2*node],tr[2*node+1]);
55    }
56
57    void update(int node,int lo,int hi,int idx){
58        if(lo==hi){ tr[node]=leaf(lo); return; }
59        int mid=(lo+hi)/2;
60        if(idx<=mid) update(2*node,lo,mid,idx);
61        else update(2*node+1,mid+1,hi,idx);
62        tr[node]=merge(tr[2*node],tr[2*node+1]);
63    }
64
65    Node query(int node,int lo,int hi,int l,int r){
66        if(l<=lo && hi<=r) return tr[node];
67        int mid=(lo+hi)/2;
68        if(r<=mid) return query(2*node,lo,mid,l,r);
69        if(l>mid) return query(2*node+1,mid+1,hi,l,r);
70        return merge(query(2*node,lo,mid,l,r), query(2*node+1,mid+1,hi,l,r));
71    }
72};
73class Solution {
74public:
75    vector<long long> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) {
76        int n = nums.size();
77        Tree tr(n);
78
79        auto isPeak = [&](int i){
80            if(i<=0 || i>=n-1) return false;
81            return nums[i]>nums[i-1] && nums[i]>nums[i+1];
82        };
83
84        for(int i=0;i<n;i++) tr.p[i] = isPeak(i)?1:0;
85        tr.build(1,0,n-1);
86
87        auto refresh = [&](int i){
88            if(i<0||i>=n) return;
89            int v = isPeak(i)?1:0;
90            if(tr.p[i]!=v){ tr.p[i]=v; tr.update(1,0,n-1,i); }
91        };
92
93        vector<long long> ans;
94        for(auto &qu : queries){
95            if(qu[0]==1){
96                int l=qu[1], r=qu[2];
97                if(r-l+1<3){ ans.push_back(0); continue; }
98                ll len = r-l+1;
99                ll tot = (len-1)*(len-2)/2;
100                Node res = tr.query(1,0,n-1,l,r);
101                ans.push_back(tot - res.val);
102            } else {
103                int idx=qu[1], val=qu[2];
104                nums[idx]=val;
105                refresh(idx-1); refresh(idx); refresh(idx+1);
106            }
107        }
108        return ans;
109    }
110};