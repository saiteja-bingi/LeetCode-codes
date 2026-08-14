// Last updated: 14/8/2026, 10:58:14 pm
1#define ll long long
2class Solution {
3public:
4    struct Node{
5        ll first,second;
6        ll seclast,last;
7        ll peaks,len;
8    };
9
10    vector<Node>tree;
11    vector<ll>nums;
12
13    Node combine(const Node& l,const Node& r){
14        if(l.len==0) return r;
15        if(r.len==0) return l;
16        Node res;
17
18        res.peaks=l.peaks+r.peaks;
19        res.len=l.len+r.len;
20        
21        res.first=l.first;
22        if(l.len>=2) res.second=l.second;
23        else res.second=r.first;
24
25        res.last=r.last;
26        if(r.len>=2) res.seclast=r.seclast;
27        else res.seclast=l.last;
28
29        if(l.len>=2&&r.len>=1){
30            if(l.seclast<l.last&&l.last>r.first) res.peaks++;
31        }
32        if(r.len>=2&&l.len>=1){
33            if(r.first>r.second&&r.first>l.last) res.peaks++;
34        }
35        return res;
36    }
37
38    void build(ll node,ll l,ll r){
39        if(l==r){
40            tree[node]={nums[l],nums[l],nums[l],nums[l],0,1};
41            return;
42        }
43        ll mid=(l+r)/2;
44        build(2*node,l,mid);
45        build(2*node+1,mid+1,r);
46        tree[node]=combine(tree[node*2],tree[node*2+1]);
47    }
48
49    void update(ll node,ll l,ll r,ll idx,ll val){
50        if(l==r){
51            nums[idx]=val;
52            tree[node]={val,val,val,val,0,1};
53            return;
54        }
55        ll mid=(l+r)/2;
56        if(idx<=mid) update(2*node,l,mid,idx,val);
57        else update(2*node+1,mid+1,r,idx,val);
58        tree[node]=combine(tree[node*2],tree[node*2+1]);
59    }
60
61    Node query(ll node,ll l,ll r,ll ql,ll qr){
62        if(qr<l||r<ql) return {0,0,0,0,0,0};
63        if(ql<=l&&qr>=r) return tree[node];
64        int mid=(l+r)/2;
65        Node left=query(2*node,l,mid,ql,qr);
66        Node right=query(2*node+1,mid+1,r,ql,qr);
67        return combine(left,right);
68    }
69    vector<int> countOfPeaks(vector<int>& nums_, vector<vector<int>>& queries) {
70        ll n=nums_.size();
71        nums.assign(n,0);
72        for(int i=0;i<n;i++) nums[i]=nums_[i]; 
73        tree.assign(4*n,Node());
74        build(1,0,n-1);
75        vector<int>ans;
76        for(auto q:queries){
77            if(q[0]==1){
78                Node k=query(1,0,n-1,q[1],q[2]);
79                ans.push_back(k.peaks);
80            }
81            else{
82                update(1,0,n-1,q[1],q[2]);
83            }
84        }
85        return ans;
86    }
87};