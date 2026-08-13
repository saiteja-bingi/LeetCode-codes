// Last updated: 13/8/2026, 10:56:26 pm
1class Solution {
2public:
3    struct Node{
4        int len;
5        int pref,suf,best;
6        char left,right;
7    };
8    vector<Node>tree;
9    string s;
10    Node combine(const Node&l,const Node&r){
11        Node res;
12        res.len=l.len+r.len;
13        res.left=l.left;
14        res.right=r.right;
15
16        res.pref=l.pref;
17        res.suf=r.suf;
18        res.best=max(l.best,r.best);
19
20        if(l.right==r.left){
21            res.best=max(res.best,l.suf+r.pref);
22            if(l.pref==l.len) res.pref=l.pref+r.pref;
23            if(r.suf==r.len) res.suf=l.suf+r.suf;
24        }
25        return res;
26    }
27    void build(int node,int l,int r){
28        if(l==r){
29            tree[node]={1,1,1,1,s[l],s[l]};
30            return;
31        }
32        int mid=(l+r)/2;
33        build(2*node,l,mid);
34        build(2*node+1,mid+1,r);
35        tree[node]=combine(tree[2*node],tree[2*node+1]);
36    }
37    void update(int node,int l,int r,int idx,char c){
38        if(l==r){
39            s[idx]=c;
40            tree[node]={1,1,1,1,c,c};
41            return;
42        }
43        int mid=(l+r)/2;
44        if(idx<=mid) update(2*node,l,mid,idx,c);
45        else update(2*node+1,mid+1,r,idx,c);
46        tree[node]=combine(tree[2*node],tree[2*node+1]);
47    }
48    vector<int> longestRepeating(string s1, string queryCharacters, vector<int>& queryIndices) {
49        s=s1;
50        int n=s.size();
51        tree.assign(4*n,Node());
52        build(1,0,n-1);
53        int k=queryIndices.size();
54        vector<int>ans(k);
55        for(int i=0;i<k;i++){
56            update(1,0,n-1,queryIndices[i],queryCharacters[i]);
57            ans[i]=tree[1].best;
58        }
59        return ans;
60    }
61};