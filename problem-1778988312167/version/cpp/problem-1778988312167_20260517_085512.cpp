// Last updated: 17/5/2026, 8:55:12 am
1#define ll long long
2ll mod=1e9+7;
3class Solution {
4public:
5    int countKthRoots(int l, int r, int k) {
6        if(k==1){
7            return r-l+1;
8        }
9        int m=ceil(pow(l,1.0/k));
10        int n=floor(pow(r,1.0/k));
11        int e1=m-1,e2=n+1;
12        ll v=1,c=0;
13        for(int i=0;i<k;i++){
14            if((__int128)v*e1>1e9){
15                v=1e9+1;
16                break;
17            }
18            v*=e1;
19        }
20        if(e1>=0&&v<=r&&v>=l) c++;
21        v=1;
22        for(int i=0;i<k;i++){
23            if((__int128)v*e2>1e9){
24                v=1e9+1;
25                break;
26            }
27            v*=e2;
28        }
29        if(e2<=1e9&&v<=r&&v>=l) c++;
30        return max(0,n-m+1)+c;
31    }
32};