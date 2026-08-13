// Last updated: 14/8/2026, 12:05:30 am
1class NumArray {
2public:
3    vector<int>nums;
4    vector<long long>tree;
5    int n;
6
7    void build(int node,int l,int r){
8        if(l==r){
9            tree[node]=nums[l];
10            return;
11        }
12        int mid=(l+r)/2;
13        build(2*node,l,mid);
14        build(2*node+1,mid+1,r);
15        tree[node]=tree[2*node]+tree[2*node+1];
16    }
17
18    NumArray(vector<int>& nums_) {
19        nums=nums_;
20        n=nums.size();
21        tree.assign(4*n,0);
22        build(1,0,n-1);
23    }
24
25    void updater(int node,int l,int r,int idx,int val){
26        if(l==r){
27            nums[idx]=val;
28            tree[node]=val;
29            return;
30        }
31        int mid=(l+r)/2;
32        if(idx<=mid) updater(2*node,l,mid,idx,val);
33        else updater(2*node+1,mid+1,r,idx,val);
34        tree[node]=tree[2*node]+tree[2*node+1];
35    }
36    
37    void update(int index, int val) {
38        updater(1,0,n-1,index,val);
39    }
40    int query(int node,int l,int r,int ql,int qr){
41        if(qr<l||r<ql) return 0;
42        if(ql<=l&&qr>=r) return tree[node];
43        int mid=(l+r)/2;
44        return query(2*node,l,mid,ql,qr)+query(2*node+1,mid+1,r,ql,qr);
45    }
46    int sumRange(int left, int right) {
47        return query(1,0,n-1,left,right);
48    }
49};
50
51/**
52 * Your NumArray object will be instantiated and called as such:
53 * NumArray* obj = new NumArray(nums);
54 * obj->update(index,val);
55 * int param_2 = obj->sumRange(left,right);
56 */