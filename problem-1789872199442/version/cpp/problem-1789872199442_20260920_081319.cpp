// Last updated: 20/9/2026, 8:13:19 am
1class Solution {
2public:
3    long long countIntersectingIntervals(vector<vector<int>>& arr) {
4        sort(arr.begin(),arr.end());
5        int n=arr.size();
6        long long c=0;
7        for(int i=0;i<n;i++){
8            int ele=arr[i][1];
9            auto it=upper_bound(arr.begin(),arr.end(),ele,
10                    [](int x,const vector<int>&p){
11                        return x<p[0];
12                    });
13            // cout<<it-arr.begin();
14            if(it==arr.end()){
15                c+=n-i-1;
16            }
17            else{
18                c+=(it-arr.begin())-i-1;
19            }
20        }
21        return c;
22    }
23};