// Last updated: 16/08/2026, 08:26:03
1
2/*
3    every one start at same time->period sec
4    red=period-light[i]
5
6    r<li->0;
7    else wait
8    period-r
9    min(max wait time)
10*/
11
12bool pos(int mid,int pe,auto&li,auto&at){
13    int m=li.size();
14    int n=at.size();
15    int j=0,i=0;
16    for(i=0;i<n&&j<m;i++){
17        if(at[i]<li[j]) continue;
18        else if(pe-at[i]<=mid) continue;
19        else{
20            j++;
21        }
22    }
23    return i==n;
24}
25
26class Solution {
27public:
28    int minPenalty(int pe, vector<int>& li, vector<int>& at) {
29        for(auto&x:at) x%=pe;
30        sort(li.begin(),li.end());
31        sort(at.begin(),at.end());
32        
33        int l=0,h=0;
34        for(auto it:at){
35            if(it>=li.back()) l=max(l,pe-it);
36            if(it>=li[0]) h=max(h,pe-it);
37        }
38        int ans=0;
39        while(l<=h){
40            int mid=l+(h-l)/2;
41            if(pos(mid,pe,li,at)){
42                ans=mid;
43                h=mid-1;
44            }
45            else l=mid+1;
46        }
47        return ans;
48    }
49};