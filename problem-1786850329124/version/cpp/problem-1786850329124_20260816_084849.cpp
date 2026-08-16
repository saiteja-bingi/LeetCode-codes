// Last updated: 16/08/2026, 08:48:49
1class Solution {
2public:
3    // bool pos(int m,auto&l,auto&r){
4    //     int n=l.size();
5    //     for(int i=0;i<n-1;i++){
6    //         if(r[i+1]-l[i]>=mid) return true;
7    //     }
8    //     return false;
9    // }
10    int maximumGap(string sk, string st) {
11        int l=0,m=st.size(),ans=0,n=sk.size();
12        int h=m-1;
13        vector<int>ll,rr;
14        int j=0;
15        for(int i=0;i<n;i++){
16            while(sk[i]!=st[j]) j++;
17            ll.push_back(j);
18            j++;
19        }
20        j=m-1;
21        for(int i=n-1;i>=0;i--){
22            while(sk[i]!=st[j]) j--;
23            rr.push_back(j);
24            j--;
25        }
26        reverse(rr.begin(),rr.end());
27        // int ans=0;
28        for(int i=0;i<n-1;i++){
29            ans=max(ans,rr[i+1]-ll[i]);
30        }
31        // while(l<=h){
32        //     int mid=l+(h-l)/2;
33        //     if(pos(mid,ll,rr)){
34        //         ans=mid;
35        //         l=mid+1;
36        //     }
37        //     else h=mid-1;
38        // }
39        return ans;
40    }
41};