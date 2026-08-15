// Last updated: 15/8/2026, 8:24:28 am
1struct Dst{
2    struct Node{
3        bool event=false;
4        bool full=false;
5        int left=0;
6        int right=0;
7    };
8    vector<Node>pool;
9    int root;
10    long long lo,hi;
11    Dst(long long lo_,long long hi_):lo(lo_),hi(hi_){
12        pool.push_back(Node());
13        pool.push_back(Node());
14        root=1;
15    }
16    int newNode(){
17        pool.push_back(Node());
18        return (int)pool.size()-1;
19    }
20
21    bool canupdate(int node,long long l,long long r,long long st,long long en){
22        if(node==0) return false;
23        if(en<l||r<st) return 0;
24        if(pool[node].full) return 1;
25        if(st<=l&&r<=en) return pool[node].event;
26        long long mid=l+(r-l)/2;
27        bool left=canupdate(pool[node].left,l,mid,st,en);
28        bool right=canupdate(pool[node].right,mid+1,r,st,en);
29        return left||right;
30    }
31    void markbook(int node,long long l,long long r,long long st,long long en){
32        if(en<l||r<st) return ;
33        if(st<=l&&r<=en){
34           pool[node].event=true;
35           pool[node].full=true;
36           return;
37        }
38        long long mid=l+(r-l)/2;
39        if(st<=mid){
40            if(pool[node].left==0) pool[node].left=newNode();
41            markbook(pool[node].left,l,mid,st,en);
42        }
43        if(en>mid){
44            if(pool[node].right==0) pool[node].right=newNode();
45            markbook(pool[node].right,mid+1,r,st,en);
46        }
47        pool[node].event=true;
48    }
49};
50
51class MyCalendar {
52public:
53    Dst tree;
54    MyCalendar():tree(0,1000000000){}
55    
56    bool book(int startTime, int endTime) {
57        bool k= tree.canupdate(1,0,1000000000,startTime,endTime-1);
58        if(k) return false;
59        tree.markbook(1,0,1000000000,startTime,endTime-1);
60        return true;
61    }
62};
63