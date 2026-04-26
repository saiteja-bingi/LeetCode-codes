// Last updated: 26/4/2026, 9:07:53 am
1class Solution {
2public:
3    long long minOperations(vector<int>& arr) {
4        long long ans=0;
5        int n=arr.size();
6        int i=0,j=1;
7        vector<long long>ak(n);
8        for(int i=0;i<n;i++) ak[i]=arr[i];
9        for(int k=1;k<n;k++){
10            if(ak[k]+ans<ak[k-1]) {
11                ans+=(ak[k-1]-ak[k]-ans);
12            }
13            ak[k]+=ans;
14        }
15        return ans;
16    }
17};